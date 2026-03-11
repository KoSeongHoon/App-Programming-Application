import { useState, useEffect } from "react";

function Clock() {
  const [now, setNow] = useState(new Date());
  useEffect(() => {
    const t = setInterval(() => setNow(new Date()), 1000);
    return () => clearInterval(t);
  }, []);
  const pad = n => String(n).padStart(2, "0");
  const days = ["일요일","월요일","화요일","수요일","목요일","금요일","토요일"];
  return (
    <div style={{textAlign:"center", marginBottom:4}}>
      <div style={{fontSize:56, fontWeight:700, letterSpacing:2, color:"#1e293b", lineHeight:1}}>
        {pad(now.getHours())}:{pad(now.getMinutes())}:{pad(now.getSeconds())}
      </div>
      <div style={{fontSize:16, color:"#64748b", marginTop:6}}>
        {now.getFullYear()}년 {now.getMonth()+1}월 {now.getDate()}일 {days[now.getDay()]}
      </div>
    </div>
  );
}

function SearchBar() {
  const [q, setQ] = useState("");
  const submit = () => {
    if (q.trim()) window.open(`https://www.google.com/search?q=${encodeURIComponent(q)}`, "_blank");
  };
  return (
    <div style={{display:"flex", gap:8, maxWidth:520, margin:"0 auto", width:"100%"}}>
      <input
        value={q}
        onChange={e => setQ(e.target.value)}
        onKeyDown={e => e.key==="Enter" && submit()}
        placeholder="🔍  Google 검색..."
        style={{
          flex:1, padding:"12px 18px", borderRadius:32, border:"2px solid #e2e8f0",
          fontSize:15, outline:"none", background:"#f8fafc", color:"#1e293b",
          boxShadow:"0 2px 8px rgba(0,0,0,0.06)"
        }}
        onFocus={e => e.target.style.border="2px solid #6366f1"}
        onBlur={e => e.target.style.border="2px solid #e2e8f0"}
      />
      <button onClick={submit} style={{
        padding:"12px 22px", borderRadius:32, border:"none",
        background:"linear-gradient(135deg,#6366f1,#8b5cf6)", color:"#fff",
        fontWeight:600, fontSize:15, cursor:"pointer", boxShadow:"0 2px 8px rgba(99,102,241,0.3)"
      }}>검색</button>
    </div>
  );
}

function WeatherCard() {
  const [weather, setWeather] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    async function load() {
      try {
        const res = await fetch("https://api.anthropic.com/v1/messages", {
          method:"POST",
          headers:{"Content-Type":"application/json"},
          body: JSON.stringify({
            model:"claude-sonnet-4-20250514",
            max_tokens:500,
            tools:[{type:"web_search_20250305",name:"web_search"}],
            messages:[{role:"user",content:'서울 오늘 날씨를 검색 후 순수 JSON만 반환해. 다른 텍스트 절대 없이: {"city":"서울","temp":숫자,"condition":"날씨설명","humidity":숫자,"wind":숫자,"high":숫자,"low":숫자,"icon":"날씨이모지"}'}]
          })
        });
        const data = await res.json();
        const txt = data.content.map(i=>i.text||"").join("");
        const match = txt.match(/\{[\s\S]*\}/);
        if (match) setWeather(JSON.parse(match[0]));
        else throw new Error();
      } catch {
        setWeather({city:"서울",temp:"--",condition:"정보 없음",humidity:"--",wind:"--",high:"--",low:"--",icon:"🌤️"});
      }
      setLoading(false);
    }
    load();
  }, []);

  return (
    <div style={{
      background:"linear-gradient(135deg,#6366f1 0%,#8b5cf6 60%,#a78bfa 100%)",
      borderRadius:20, padding:"24px 28px", color:"#fff", flex:1, minWidth:200,
      boxShadow:"0 8px 24px rgba(99,102,241,0.25)"
    }}>
      <div style={{fontSize:13, opacity:0.85, marginBottom:4}}>📍 {weather?.city||"서울"} · 오늘 날씨</div>
      {loading ? (
        <div style={{fontSize:14, opacity:0.8, marginTop:16}}>날씨 불러오는 중...</div>
      ) : (
        <>
          <div style={{display:"flex", alignItems:"center", gap:12, marginTop:4}}>
            <span style={{fontSize:46}}>{weather.icon}</span>
            <div>
              <div style={{fontSize:42, fontWeight:700, lineHeight:1}}>{weather.temp}°</div>
              <div style={{fontSize:14, opacity:0.9, marginTop:2}}>{weather.condition}</div>
            </div>
          </div>
          <div style={{display:"flex", gap:14, marginTop:12, fontSize:13, opacity:0.85, flexWrap:"wrap"}}>
            <span>💧 {weather.humidity}%</span>
            <span>💨 {weather.wind}m/s</span>
            <span>⬆{weather.high}° ⬇{weather.low}°</span>
          </div>
        </>
      )}
    </div>
  );
}

function TodoCard() {
  const [todos, setTodos] = useState([{id:1,text:"오늘 할 일을 추가해 보세요",done:false}]);
  const [input, setInput] = useState("");
  const add = () => {
    if (!input.trim()) return;
    setTodos(t => [...t, {id:Date.now(), text:input.trim(), done:false}]);
    setInput("");
  };
  const toggle = id => setTodos(t => t.map(i => i.id===id ? {...i,done:!i.done} : i));
  const remove = id => setTodos(t => t.filter(i => i.id!==id));
  return (
    <div style={{background:"#fff", borderRadius:20, padding:"20px 22px", boxShadow:"0 4px 16px rgba(0,0,0,0.07)", flex:1, minWidth:200}}>
      <div style={{fontWeight:700, fontSize:15, color:"#1e293b", marginBottom:12}}>✅ 오늘의 할 일</div>
      <div style={{display:"flex", gap:6, marginBottom:10}}>
        <input
          value={input}
          onChange={e=>setInput(e.target.value)}
          onKeyDown={e=>e.key==="Enter"&&add()}
          placeholder="할 일 추가..."
          style={{flex:1,padding:"8px 12px",borderRadius:12,border:"1.5px solid #e2e8f0",fontSize:13,outline:"none",color:"#1e293b",background:"#f8fafc"}}
          onFocus={e=>e.target.style.border="1.5px solid #6366f1"}
          onBlur={e=>e.target.style.border="1.5px solid #e2e8f0"}
        />
        <button onClick={add} style={{padding:"8px 14px",borderRadius:12,border:"none",background:"#6366f1",color:"#fff",fontWeight:700,cursor:"pointer",fontSize:18,lineHeight:1}}>+</button>
      </div>
      <div style={{maxHeight:140, overflowY:"auto"}}>
        {todos.map(t => (
          <div key={t.id} style={{display:"flex",alignItems:"center",gap:8,padding:"6px 2px",borderBottom:"1px solid #f1f5f9"}}>
            <input type="checkbox" checked={t.done} onChange={()=>toggle(t.id)} style={{accentColor:"#6366f1",width:16,height:16,cursor:"pointer"}}/>
            <span style={{flex:1,fontSize:13,color:t.done?"#94a3b8":"#334155",textDecoration:t.done?"line-through":"none"}}>{t.text}</span>
            <button onClick={()=>remove(t.id)} style={{background:"none",border:"none",cursor:"pointer",color:"#cbd5e1",fontSize:15,lineHeight:1}}>✕</button>
          </div>
        ))}
      </div>
    </div>
  );
}

function NewsSection() {
  const [news, setNews] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    async function load() {
      try {
        const res = await fetch("https://api.anthropic.com/v1/messages", {
          method:"POST",
          headers:{"Content-Type":"application/json"},
          body: JSON.stringify({
            model:"claude-sonnet-4-20250514",
            max_tokens:1000,
            tools:[{type:"web_search_20250305",name:"web_search"}],
            messages:[{role:"user",content:'오늘 한국 주요 뉴스 5개 검색 후 순수 JSON 배열만 반환. 다른 텍스트 절대 없이: [{"title":"제목","category":"정치/경제/사회/IT/스포츠 중 하나","time":"N분/시간 전","emoji":"이모지"}]'}]
          })
        });
        const data = await res.json();
        const txt = data.content.map(i=>i.text||"").join("");
        const match = txt.match(/\[[\s\S]*\]/);
        if (match) setNews(JSON.parse(match[0]));
        else throw new Error();
      } catch {
        setNews([{title:"뉴스를 불러오지 못했습니다. 잠시 후 다시 시도해 주세요.",category:"오류",time:"",emoji:"⚠️"}]);
      }
      setLoading(false);
    }
    load();
  }, []);

  const catColor = {정치:"#ef4444",경제:"#f59e0b",사회:"#10b981",IT:"#6366f1",스포츠:"#3b82f6",오류:"#94a3b8"};

  return (
    <div style={{background:"#fff",borderRadius:20,padding:"20px 22px",boxShadow:"0 4px 16px rgba(0,0,0,0.07)"}}>
      <div style={{display:"flex",justifyContent:"space-between",alignItems:"center",marginBottom:14}}>
        <div style={{fontWeight:700,fontSize:15,color:"#1e293b"}}>📰 오늘의 주요 뉴스</div>
        <div style={{fontSize:11,color:"#94a3b8",background:"#f1f5f9",padding:"3px 10px",borderRadius:20}}>AI 실시간 검색</div>
      </div>
      {loading ? (
        <div style={{color:"#94a3b8",fontSize:14,padding:"24px 0",textAlign:"center"}}>✨ 뉴스 불러오는 중...</div>
      ) : (
        <div style={{display:"flex",flexDirection:"column",gap:8}}>
          {news.map((n,i) => (
            <div key={i} style={{
              display:"flex",alignItems:"center",gap:12,padding:"12px 14px",
              background:"#f8fafc",borderRadius:12,cursor:"default",transition:"background 0.15s"
            }}
              onMouseEnter={e=>e.currentTarget.style.background="#f1f5f9"}
              onMouseLeave={e=>e.currentTarget.style.background="#f8fafc"}
            >
              <span style={{fontSize:22,flexShrink:0}}>{n.emoji}</span>
              <div style={{flex:1}}>
                <div style={{fontSize:14,fontWeight:500,color:"#1e293b",lineHeight:1.45}}>{n.title}</div>
                <div style={{display:"flex",gap:8,marginTop:5,alignItems:"center"}}>
                  <span style={{
                    fontSize:11,fontWeight:600,padding:"2px 8px",borderRadius:20,
                    background:(catColor[n.category]||"#94a3b8")+"22",
                    color:catColor[n.category]||"#94a3b8"
                  }}>{n.category}</span>
                  {n.time&&<span style={{fontSize:11,color:"#94a3b8"}}>{n.time}</span>}
                </div>
              </div>
            </div>
          ))}
        </div>
      )}
    </div>
  );
}

export default function App() {
  return (
    <div style={{
      minHeight:"100vh",
      background:"linear-gradient(160deg,#eef2ff 0%,#faf5ff 50%,#f0fdf4 100%)",
      fontFamily:"'Segoe UI',system-ui,sans-serif",
      padding:"32px 20px"
    }}>
      <div style={{maxWidth:700, margin:"0 auto", display:"flex", flexDirection:"column", gap:18}}>
        <Clock />
        <SearchBar />
        <div style={{display:"flex", gap:16, flexWrap:"wrap"}}>
          <WeatherCard />
          <TodoCard />
        </div>
        <NewsSection />
        <div style={{textAlign:"center",fontSize:12,color:"#c7d2fe",paddingBottom:4}}>
          ✨ Claude AI가 실시간으로 날씨와 뉴스를 검색합니다
        </div>
      </div>
    </div>
  );
}
