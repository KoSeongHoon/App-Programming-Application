import { useState, useEffect, useRef } from "react";

const THEMES = [
  {label:"🌸 라벤더", bg:"linear-gradient(160deg,#eef2ff 0%,#faf5ff 50%,#f0fdf4 100%)"},
  {label:"🌅 선셋", bg:"linear-gradient(160deg,#fff7ed 0%,#fce7f3 50%,#fef9c3 100%)"},
  {label:"🌊 오션", bg:"linear-gradient(160deg,#e0f2fe 0%,#f0f9ff 50%,#ecfdf5 100%)"},
  {label:"🌿 포레스트", bg:"linear-gradient(160deg,#f0fdf4 0%,#dcfce7 50%,#f0fdfa 100%)"},
  {label:"🍑 피치", bg:"linear-gradient(160deg,#fff1f2 0%,#fdf4ff 50%,#fff7ed 100%)"},
];

function Clock({fontSize}) {
  const [now, setNow] = useState(new Date());
  useEffect(() => { const t = setInterval(()=>setNow(new Date()),1000); return()=>clearInterval(t); },[]);
  const pad = n=>String(n).padStart(2,"0");
  const days=["일요일","월요일","화요일","수요일","목요일","금요일","토요일"];
  return (
    <div style={{textAlign:"center",marginBottom:4}}>
      <div style={{fontSize:fontSize*3.5, fontWeight:700,letterSpacing:2,color:"#1e293b",lineHeight:1}}>
        {pad(now.getHours())}:{pad(now.getMinutes())}:{pad(now.getSeconds())}
      </div>
      <div style={{fontSize:fontSize*1,color:"#64748b",marginTop:6}}>
        {now.getFullYear()}년 {now.getMonth()+1}월 {now.getDate()}일 {days[now.getDay()]}
      </div>
    </div>
  );
}

function SearchBar({fontSize}) {
  const [q,setQ]=useState("");
  const submit=()=>{ if(q.trim()) window.open(`https://www.google.com/search?q=${encodeURIComponent(q)}`,"_blank"); };
  return (
    <div style={{display:"flex",gap:8,maxWidth:520,margin:"0 auto",width:"100%"}}>
      <input value={q} onChange={e=>setQ(e.target.value)} onKeyDown={e=>e.key==="Enter"&&submit()}
        placeholder="🔍  Google 검색..."
        style={{flex:1,padding:"12px 18px",borderRadius:32,border:"2px solid #e2e8f0",fontSize:fontSize*0.93,outline:"none",background:"#f8fafc",color:"#1e293b",boxShadow:"0 2px 8px rgba(0,0,0,0.06)"}}
        onFocus={e=>e.target.style.border="2px solid #6366f1"}
        onBlur={e=>e.target.style.border="2px solid #e2e8f0"}
      />
      <button onClick={submit} style={{padding:"12px 22px",borderRadius:32,border:"none",background:"linear-gradient(135deg,#6366f1,#8b5cf6)",color:"#fff",fontWeight:600,fontSize:fontSize*0.93,cursor:"pointer",boxShadow:"0 2px 8px rgba(99,102,241,0.3)"}}>검색</button>
    </div>
  );
}

function WeatherCard({fontSize}) {
  const [weather,setWeather]=useState(null);
  const [loading,setLoading]=useState(true);
  useEffect(()=>{
    async function load(){
      try{
        const res=await fetch("https://api.anthropic.com/v1/messages",{method:"POST",headers:{"Content-Type":"application/json"},body:JSON.stringify({model:"claude-sonnet-4-20250514",max_tokens:500,tools:[{type:"web_search_20250305",name:"web_search"}],messages:[{role:"user",content:'서울 오늘 날씨를 검색 후 순수 JSON만 반환해. 다른 텍스트 절대 없이: {"city":"서울","temp":숫자,"condition":"날씨설명","humidity":숫자,"wind":숫자,"high":숫자,"low":숫자,"icon":"날씨이모지"}'}]})});
        const data=await res.json();
        const txt=data.content.map(i=>i.text||"").join("");
        const match=txt.match(/\{[\s\S]*\}/);
        if(match) setWeather(JSON.parse(match[0])); else throw new Error();
      }catch{ setWeather({city:"서울",temp:"--",condition:"정보 없음",humidity:"--",wind:"--",high:"--",low:"--",icon:"🌤️"}); }
      setLoading(false);
    }
    load();
  },[]);
  return (
    <div style={{background:"linear-gradient(135deg,#6366f1 0%,#8b5cf6 60%,#a78bfa 100%)",borderRadius:20,padding:"24px 28px",color:"#fff",flex:1,minWidth:200,boxShadow:"0 8px 24px rgba(99,102,241,0.25)"}}>
      <div style={{fontSize:fontSize*0.81,opacity:0.85,marginBottom:4}}>📍 {weather?.city||"서울"} · 오늘 날씨</div>
      {loading?<div style={{fontSize:fontSize*0.87,opacity:0.8,marginTop:16}}>날씨 불러오는 중...</div>:(
        <>
          <div style={{display:"flex",alignItems:"center",gap:12,marginTop:4}}>
            <span style={{fontSize:46}}>{weather.icon}</span>
            <div>
              <div style={{fontSize:fontSize*2.5,fontWeight:700,lineHeight:1}}>{weather.temp}°</div>
              <div style={{fontSize:fontSize*0.87,opacity:0.9,marginTop:2}}>{weather.condition}</div>
            </div>
          </div>
          <div style={{display:"flex",gap:14,marginTop:12,fontSize:fontSize*0.81,opacity:0.85,flexWrap:"wrap"}}>
            <span>💧 {weather.humidity}%</span><span>💨 {weather.wind}m/s</span><span>⬆{weather.high}° ⬇{weather.low}°</span>
          </div>
        </>
      )}
    </div>
  );
}

function TodoCard({fontSize}) {
  const [todos,setTodos]=useState([{id:1,text:"오늘 할 일을 추가해 보세요",done:false}]);
  const [input,setInput]=useState("");
  const add=()=>{ if(!input.trim()) return; setTodos(t=>[...t,{id:Date.now(),text:input.trim(),done:false}]); setInput(""); };
  const toggle=id=>setTodos(t=>t.map(i=>i.id===id?{...i,done:!i.done}:i));
  const remove=id=>setTodos(t=>t.filter(i=>i.id!==id));
  return (
    <div style={{background:"#fff",borderRadius:20,padding:"20px 22px",boxShadow:"0 4px 16px rgba(0,0,0,0.07)",flex:1,minWidth:200}}>
      <div style={{fontWeight:700,fontSize:fontSize*0.93,color:"#1e293b",marginBottom:12}}>✅ 오늘의 할 일</div>
      <div style={{display:"flex",gap:6,marginBottom:10}}>
        <input value={input} onChange={e=>setInput(e.target.value)} onKeyDown={e=>e.key==="Enter"&&add()} placeholder="할 일 추가..."
          style={{flex:1,padding:"8px 12px",borderRadius:12,border:"1.5px solid #e2e8f0",fontSize:fontSize*0.81,outline:"none",color:"#1e293b",background:"#f8fafc"}}
          onFocus={e=>e.target.style.border="1.5px solid #6366f1"} onBlur={e=>e.target.style.border="1.5px solid #e2e8f0"}/>
        <button onClick={add} style={{padding:"8px 14px",borderRadius:12,border:"none",background:"#6366f1",color:"#fff",fontWeight:700,cursor:"pointer",fontSize:18,lineHeight:1}}>+</button>
      </div>
      <div style={{maxHeight:140,overflowY:"auto"}}>
        {todos.map(t=>(
          <div key={t.id} style={{display:"flex",alignItems:"center",gap:8,padding:"6px 2px",borderBottom:"1px solid #f1f5f9"}}>
            <input type="checkbox" checked={t.done} onChange={()=>toggle(t.id)} style={{accentColor:"#6366f1",width:16,height:16,cursor:"pointer"}}/>
            <span style={{flex:1,fontSize:fontSize*0.81,color:t.done?"#94a3b8":"#334155",textDecoration:t.done?"line-through":"none"}}>{t.text}</span>
            <button onClick={()=>remove(t.id)} style={{background:"none",border:"none",cursor:"pointer",color:"#cbd5e1",fontSize:15,lineHeight:1}}>✕</button>
          </div>
        ))}
      </div>
    </div>
  );
}

function StockSection({fontSize}) {
  const [stocks,setStocks]=useState(null);
  const [loading,setLoading]=useState(true);
  const [searchInput,setSearchInput]=useState("");
  const [searching,setSearching]=useState(false);
  const [searchResult,setSearchResult]=useState(null);
  useEffect(()=>{
    async function load(){
      try{
        const res=await fetch("https://api.anthropic.com/v1/messages",{method:"POST",headers:{"Content-Type":"application/json"},body:JSON.stringify({model:"claude-sonnet-4-20250514",max_tokens:1000,tools:[{type:"web_search_20250305",name:"web_search"}],messages:[{role:"user",content:'다음 항목들의 현재 시세를 검색해서 순수 JSON만 반환해. 다른 텍스트 절대 없이: {"indices":[{"name":"KOSPI","value":숫자,"change":숫자,"changePct":숫자},{"name":"KOSDAQ","value":숫자,"change":숫자,"changePct":숫자},{"name":"S&P500","value":숫자,"change":숫자,"changePct":숫자},{"name":"NASDAQ","value":숫자,"change":숫자,"changePct":숫자}],"stocks":[{"name":"삼성전자","ticker":"005930","price":숫자,"change":숫자,"changePct":숫자},{"name":"SK하이닉스","ticker":"000660","price":숫자,"change":숫자,"changePct":숫자},{"name":"NAVER","ticker":"035420","price":숫자,"change":숫자,"changePct":숫자}],"usdkrw":숫자}'}]})});
        const data=await res.json();
        const txt=data.content.map(i=>i.text||"").join("");
        const match=txt.match(/\{[\s\S]*\}/);
        if(match) setStocks(JSON.parse(match[0])); else throw new Error();
      }catch{ setStocks(null); }
      setLoading(false);
    }
    load();
  },[]);
  const searchStock=async()=>{
    if(!searchInput.trim()) return;
    setSearching(true); setSearchResult(null);
    try{
      const res=await fetch("https://api.anthropic.com/v1/messages",{method:"POST",headers:{"Content-Type":"application/json"},body:JSON.stringify({model:"claude-sonnet-4-20250514",max_tokens:500,tools:[{type:"web_search_20250305",name:"web_search"}],messages:[{role:"user",content:`"${searchInput}" 주식 현재가를 검색 후 순수 JSON만 반환. 다른 텍스트 절대 없이: {"name":"종목명","ticker":"티커","price":숫자,"change":숫자,"changePct":숫자,"high":숫자,"low":숫자,"volume":"거래량문자열"}`}]})});
      const data=await res.json();
      const txt=data.content.map(i=>i.text||"").join("");
      const match=txt.match(/\{[\s\S]*\}/);
      if(match) setSearchResult(JSON.parse(match[0])); else throw new Error();
    }catch{ setSearchResult({name:searchInput,ticker:"-",price:"조회 실패",change:0,changePct:0}); }
    setSearching(false);
  };
  const ChangeTag=({val,pct})=>{
    const up=val>=0;
    return <span style={{fontSize:fontSize*0.75,fontWeight:600,color:up?"#10b981":"#ef4444",background:up?"#d1fae5":"#fee2e2",padding:"2px 7px",borderRadius:20}}>{up?"+":""}{val} ({up?"+":""}{typeof pct==="number"?pct.toFixed(2):pct}%)</span>;
  };
  return (
    <div style={{background:"#fff",borderRadius:20,padding:"20px 22px",boxShadow:"0 4px 16px rgba(0,0,0,0.07)"}}>
      <div style={{display:"flex",justifyContent:"space-between",alignItems:"center",marginBottom:14}}>
        <div style={{fontWeight:700,fontSize:fontSize*0.93,color:"#1e293b"}}>📈 주식 & 시장 정보</div>
        <div style={{fontSize:fontSize*0.68,color:"#94a3b8",background:"#f1f5f9",padding:"3px 10px",borderRadius:20}}>AI 실시간 검색</div>
      </div>
      <div style={{display:"flex",gap:8,marginBottom:16}}>
        <input value={searchInput} onChange={e=>setSearchInput(e.target.value)} onKeyDown={e=>e.key==="Enter"&&searchStock()}
          placeholder="종목명 또는 티커 검색 (예: 카카오, AAPL)"
          style={{flex:1,padding:"9px 14px",borderRadius:12,border:"1.5px solid #e2e8f0",fontSize:fontSize*0.81,outline:"none",color:"#1e293b",background:"#f8fafc"}}
          onFocus={e=>e.target.style.border="1.5px solid #6366f1"} onBlur={e=>e.target.style.border="1.5px solid #e2e8f0"}/>
        <button onClick={searchStock} style={{padding:"9px 16px",borderRadius:12,border:"none",background:"linear-gradient(135deg,#6366f1,#8b5cf6)",color:"#fff",fontWeight:600,fontSize:fontSize*0.81,cursor:"pointer"}}>{searching?"…":"검색"}</button>
      </div>
      {searchResult&&(
        <div style={{background:"linear-gradient(135deg,#eef2ff,#f5f3ff)",borderRadius:14,padding:"14px 16px",marginBottom:14,border:"1.5px solid #c7d2fe"}}>
          <div style={{display:"flex",justifyContent:"space-between",alignItems:"flex-start"}}>
            <div><span style={{fontWeight:700,fontSize:fontSize*0.93,color:"#1e293b"}}>{searchResult.name}</span><span style={{fontSize:fontSize*0.75,color:"#94a3b8",marginLeft:6}}>{searchResult.ticker}</span></div>
            <button onClick={()=>setSearchResult(null)} style={{background:"none",border:"none",cursor:"pointer",color:"#cbd5e1",fontSize:16}}>✕</button>
          </div>
          <div style={{display:"flex",alignItems:"center",gap:10,marginTop:8}}>
            <span style={{fontSize:fontSize*1.5,fontWeight:700,color:"#1e293b"}}>{typeof searchResult.price==="number"?searchResult.price.toLocaleString():searchResult.price}</span>
            {typeof searchResult.change==="number"&&<ChangeTag val={searchResult.change} pct={searchResult.changePct}/>}
          </div>
          {searchResult.high&&<div style={{fontSize:fontSize*0.75,color:"#64748b",marginTop:6,display:"flex",gap:12}}><span>고가 {searchResult.high?.toLocaleString()}</span><span>저가 {searchResult.low?.toLocaleString()}</span>{searchResult.volume&&<span>거래량 {searchResult.volume}</span>}</div>}
        </div>
      )}
      {loading?<div style={{color:"#94a3b8",fontSize:fontSize*0.87,padding:"20px 0",textAlign:"center"}}>✨ 시장 정보 불러오는 중...</div>:stocks?(
        <>
          <div style={{display:"grid",gridTemplateColumns:"repeat(2,1fr)",gap:8,marginBottom:12}}>
            {stocks.indices?.map((idx,i)=>(
              <div key={i} style={{background:"#f8fafc",borderRadius:12,padding:"10px 14px"}}>
                <div style={{fontSize:fontSize*0.75,color:"#64748b",fontWeight:600}}>{idx.name}</div>
                <div style={{fontSize:fontSize*1.12,fontWeight:700,color:"#1e293b",marginTop:2}}>{idx.value?.toLocaleString()}</div>
                <div style={{marginTop:4}}><ChangeTag val={idx.change} pct={idx.changePct}/></div>
              </div>
            ))}
          </div>
          <div style={{marginBottom:12}}>
            <div style={{fontSize:fontSize*0.75,color:"#64748b",fontWeight:600,marginBottom:6}}>⭐ 주요 종목</div>
            <div style={{display:"flex",flexDirection:"column",gap:6}}>
              {stocks.stocks?.map((s,i)=>(
                <div key={i} style={{display:"flex",alignItems:"center",justifyContent:"space-between",background:"#f8fafc",borderRadius:12,padding:"10px 14px"}}>
                  <div><span style={{fontWeight:600,fontSize:fontSize*0.87,color:"#1e293b"}}>{s.name}</span><span style={{fontSize:fontSize*0.68,color:"#94a3b8",marginLeft:6}}>{s.ticker}</span></div>
                  <div style={{textAlign:"right"}}><div style={{fontWeight:700,fontSize:fontSize*0.87,color:"#1e293b"}}>{s.price?.toLocaleString()}원</div><div style={{marginTop:3}}><ChangeTag val={s.change} pct={s.changePct}/></div></div>
                </div>
              ))}
            </div>
          </div>
          {stocks.usdkrw&&<div style={{background:"linear-gradient(135deg,#fef9c3,#fef3c7)",borderRadius:12,padding:"10px 14px",display:"flex",justifyContent:"space-between",alignItems:"center"}}><span style={{fontWeight:600,fontSize:fontSize*0.81,color:"#92400e"}}>💱 USD / KRW</span><span style={{fontWeight:700,fontSize:fontSize,color:"#78350f"}}>{stocks.usdkrw?.toLocaleString()} 원</span></div>}
        </>
      ):<div style={{color:"#94a3b8",fontSize:fontSize*0.87,textAlign:"center",padding:"12px 0"}}>⚠️ 시장 정보를 불러오지 못했습니다.</div>}
    </div>
  );
}

function NewsSection({fontSize}) {
  const [news,setNews]=useState([]);
  const [loading,setLoading]=useState(true);
  useEffect(()=>{
    async function load(){
      try{
        const res=await fetch("https://api.anthropic.com/v1/messages",{method:"POST",headers:{"Content-Type":"application/json"},body:JSON.stringify({model:"claude-sonnet-4-20250514",max_tokens:1000,tools:[{type:"web_search_20250305",name:"web_search"}],messages:[{role:"user",content:'오늘 한국 주요 뉴스 5개 검색 후 순수 JSON 배열만 반환. 다른 텍스트 절대 없이: [{"title":"제목","category":"정치/경제/사회/IT/스포츠 중 하나","time":"N분/시간 전","emoji":"이모지"}]'}]})});
        const data=await res.json();
        const txt=data.content.map(i=>i.text||"").join("");
        const match=txt.match(/\[[\s\S]*\]/);
        if(match) setNews(JSON.parse(match[0])); else throw new Error();
      }catch{ setNews([{title:"뉴스를 불러오지 못했습니다.",category:"오류",time:"",emoji:"⚠️"}]); }
      setLoading(false);
    }
    load();
  },[]);
  const catColor={정치:"#ef4444",경제:"#f59e0b",사회:"#10b981",IT:"#6366f1",스포츠:"#3b82f6",오류:"#94a3b8"};
  return (
    <div style={{background:"#fff",borderRadius:20,padding:"20px 22px",boxShadow:"0 4px 16px rgba(0,0,0,0.07)"}}>
      <div style={{display:"flex",justifyContent:"space-between",alignItems:"center",marginBottom:14}}>
        <div style={{fontWeight:700,fontSize:fontSize*0.93,color:"#1e293b"}}>📰 오늘의 주요 뉴스</div>
        <div style={{fontSize:fontSize*0.68,color:"#94a3b8",background:"#f1f5f9",padding:"3px 10px",borderRadius:20}}>AI 실시간 검색</div>
      </div>
      {loading?<div style={{color:"#94a3b8",fontSize:fontSize*0.87,padding:"24px 0",textAlign:"center"}}>✨ 뉴스 불러오는 중...</div>:(
        <div style={{display:"flex",flexDirection:"column",gap:8}}>
          {news.map((n,i)=>(
            <div key={i} style={{display:"flex",alignItems:"center",gap:12,padding:"12px 14px",background:"#f8fafc",borderRadius:12,cursor:"default"}}
              onMouseEnter={e=>e.currentTarget.style.background="#f1f5f9"} onMouseLeave={e=>e.currentTarget.style.background="#f8fafc"}>
              <span style={{fontSize:22,flexShrink:0}}>{n.emoji}</span>
              <div style={{flex:1}}>
                <div style={{fontSize:fontSize*0.87,fontWeight:500,color:"#1e293b",lineHeight:1.45}}>{n.title}</div>
                <div style={{display:"flex",gap:8,marginTop:5,alignItems:"center"}}>
                  <span style={{fontSize:fontSize*0.68,fontWeight:600,padding:"2px 8px",borderRadius:20,background:(catColor[n.category]||"#94a3b8")+"22",color:catColor[n.category]||"#94a3b8"}}>{n.category}</span>
                  {n.time&&<span style={{fontSize:fontSize*0.68,color:"#94a3b8"}}>{n.time}</span>}
                </div>
              </div>
            </div>
          ))}
        </div>
      )}
    </div>
  );
}

// ─── 설정 패널 ────────────────────────────────────────────────
function SettingsPanel({show, onClose, settings, onChange, fileRef, onUpload}) {
  if (!show) return null;
  const {themeIdx, bgImage, bgList, widgets, fontSize} = settings;

  const Section = ({title, children}) => (
    <div style={{marginBottom:20}}>
      <div style={{fontSize:11,fontWeight:700,color:"#94a3b8",letterSpacing:1,textTransform:"uppercase",marginBottom:8}}>{title}</div>
      {children}
    </div>
  );

  const Toggle = ({label, checked, onToggle}) => (
    <div style={{display:"flex",justifyContent:"space-between",alignItems:"center",padding:"8px 0",borderBottom:"1px solid #f1f5f9"}}>
      <span style={{fontSize:13,color:"#334155"}}>{label}</span>
      <div onClick={onToggle} style={{width:40,height:22,borderRadius:11,background:checked?"#6366f1":"#e2e8f0",cursor:"pointer",position:"relative",transition:"background 0.2s"}}>
        <div style={{position:"absolute",top:3,left:checked?20:3,width:16,height:16,borderRadius:"50%",background:"#fff",boxShadow:"0 1px 4px rgba(0,0,0,0.2)",transition:"left 0.2s"}}/>
      </div>
    </div>
  );

  return (
    <div style={{position:"absolute",top:56,right:0,background:"#fff",borderRadius:20,padding:"20px",boxShadow:"0 8px 40px rgba(0,0,0,0.16)",width:280,zIndex:300,maxHeight:"80vh",overflowY:"auto"}}>
      <div style={{display:"flex",justifyContent:"space-between",alignItems:"center",marginBottom:18}}>
        <span style={{fontWeight:700,fontSize:15,color:"#1e293b"}}>⚙️ 설정</span>
        <button onClick={onClose} style={{background:"none",border:"none",cursor:"pointer",color:"#94a3b8",fontSize:18,lineHeight:1}}>✕</button>
      </div>

      {/* 배경 */}
      <Section title="🖼️ 배경">
        <input ref={fileRef} type="file" accept="image/*" multiple onChange={onUpload} style={{display:"none"}}/>
        <button onClick={()=>fileRef.current.click()} style={{width:"100%",padding:"9px",borderRadius:12,border:"2px dashed #c7d2fe",background:"#f5f3ff",color:"#6366f1",fontWeight:600,fontSize:13,cursor:"pointer",marginBottom:8}}>
          + 이미지 업로드
        </button>
        {bgList.length>0&&(
          <div style={{display:"flex",flexDirection:"column",gap:5,marginBottom:8}}>
            {bgList.map((img,i)=>(
              <div key={i} style={{display:"flex",alignItems:"center",gap:8,padding:"5px 8px",borderRadius:10,background:bgImage===img.url?"#eef2ff":"#f8fafc",border:bgImage===img.url?"1.5px solid #6366f1":"1.5px solid transparent",cursor:"pointer"}}
                onClick={()=>onChange("bgImage",img.url)}>
                <img src={img.url} alt="" style={{width:38,height:28,objectFit:"cover",borderRadius:6,flexShrink:0}}/>
                <span style={{fontSize:12,color:"#334155",overflow:"hidden",textOverflow:"ellipsis",whiteSpace:"nowrap",flex:1}}>{img.name}</span>
                <button onClick={e=>{e.stopPropagation();onChange("removeBg",i);}} style={{background:"none",border:"none",cursor:"pointer",color:"#cbd5e1",fontSize:14}}>✕</button>
              </div>
            ))}
          </div>
        )}
        <div style={{display:"flex",flexWrap:"wrap",gap:6}}>
          {THEMES.map((t,i)=>(
            <button key={i} onClick={()=>onChange("theme",i)} style={{flex:"1 1 calc(50% - 3px)",padding:"7px 6px",borderRadius:10,border:themeIdx===i&&!bgImage?"2px solid #6366f1":"2px solid #e2e8f0",background:themeIdx===i&&!bgImage?"#eef2ff":"#f8fafc",fontSize:12,cursor:"pointer",color:"#334155",fontWeight:themeIdx===i&&!bgImage?700:400}}>
              {t.label}
            </button>
          ))}
        </div>
        {bgImage&&<button onClick={()=>onChange("bgImage",null)} style={{width:"100%",marginTop:8,padding:"7px",borderRadius:10,border:"none",background:"#f1f5f9",color:"#64748b",fontSize:12,fontWeight:600,cursor:"pointer"}}>🎨 기본 배경으로 초기화</button>}
      </Section>

      {/* 위젯 표시 */}
      <Section title="🧩 위젯 표시">
        <Toggle label="☀️ 날씨" checked={widgets.weather} onToggle={()=>onChange("widget","weather")}/>
        <Toggle label="✅ 할 일 목록" checked={widgets.todo} onToggle={()=>onChange("widget","todo")}/>
        <Toggle label="📈 주식 & 시장" checked={widgets.stock} onToggle={()=>onChange("widget","stock")}/>
        <Toggle label="📰 뉴스" checked={widgets.news} onToggle={()=>onChange("widget","news")}/>
      </Section>

      {/* 폰트 크기 */}
      <Section title="🔠 폰트 크기">
        <div style={{display:"flex",alignItems:"center",gap:10}}>
          <span style={{fontSize:11,color:"#94a3b8"}}>작게</span>
          <input type="range" min={12} max={20} value={fontSize} onChange={e=>onChange("fontSize",Number(e.target.value))}
            style={{flex:1,accentColor:"#6366f1"}}/>
          <span style={{fontSize:11,color:"#94a3b8"}}>크게</span>
        </div>
        <div style={{textAlign:"center",fontSize:12,color:"#6366f1",fontWeight:600,marginTop:4}}>{fontSize}px</div>
      </Section>
    </div>
  );
}

// ─── 메인 앱 ──────────────────────────────────────────────────
export default function App() {
  const [showSettings, setShowSettings] = useState(false);
  const [themeIdx, setThemeIdx] = useState(0);
  const [bgImage, setBgImage] = useState(null);
  const [bgList, setBgList] = useState([]);
  const [fontSize, setFontSize] = useState(16);
  const [widgets, setWidgets] = useState({weather:true, todo:true, stock:true, news:true});
  const [spinning, setSpinning] = useState(false);
  const fileRef = useRef(null);

  const handleChange = (type, val) => {
    if (type==="theme") { setThemeIdx(val); setBgImage(null); }
    else if (type==="bgImage") setBgImage(val);
    else if (type==="removeBg") {
      const next = bgList.filter((_,i)=>i!==val);
      setBgList(next);
      if (bgImage===bgList[val]?.url) setBgImage(next.length>0?next[next.length-1].url:null);
    }
    else if (type==="widget") setWidgets(w=>({...w,[val]:!w[val]}));
    else if (type==="fontSize") setFontSize(val);
  };

  const handleUpload = (e) => {
    Array.from(e.target.files).forEach(file=>{
      const r=new FileReader();
      r.onload=ev=>{ const url=ev.target.result; setBgList(p=>[...p,{url,name:file.name}]); setBgImage(url); };
      r.readAsDataURL(file);
    });
    e.target.value="";
  };

  const bgStyle = bgImage
    ? {backgroundImage:`url(${bgImage})`,backgroundSize:"cover",backgroundPosition:"center",backgroundAttachment:"fixed"}
    : {background: THEMES[themeIdx].bg};

  return (
    <div style={{minHeight:"100vh",...bgStyle,fontFamily:"'Segoe UI',system-ui,sans-serif",padding:"32px 20px",position:"relative",transition:"background 0.4s"}}>
      {bgImage&&<div style={{position:"fixed",inset:0,background:"rgba(255,255,255,0.18)",zIndex:0,pointerEvents:"none"}}/>}

      <style>{`@keyframes spin{from{transform:rotate(0deg)}to{transform:rotate(360deg)}}`}</style>

      {/* 톱니바퀴 설정 버튼 */}
      <div style={{position:"absolute",top:20,right:20,zIndex:200}}>
        <button
          onClick={()=>setShowSettings(v=>!v)}
          onMouseEnter={()=>setSpinning(true)}
          onMouseLeave={()=>setSpinning(false)}
          style={{width:42,height:42,borderRadius:"50%",border:"none",cursor:"pointer",background:"rgba(255,255,255,0.88)",boxShadow:"0 4px 16px rgba(0,0,0,0.14)",backdropFilter:"blur(10px)",display:"flex",alignItems:"center",justifyContent:"center",padding:0}}
        >
          <svg width="22" height="22" viewBox="0 0 24 24" fill="none" stroke="#6366f1" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round"
            style={{animation: spinning?"spin 1.2s linear infinite":"none"}}>
            <circle cx="12" cy="12" r="3"/>
            <path d="M19.4 15a1.65 1.65 0 0 0 .33 1.82l.06.06a2 2 0 0 1-2.83 2.83l-.06-.06a1.65 1.65 0 0 0-1.82-.33 1.65 1.65 0 0 0-1 1.51V21a2 2 0 0 1-4 0v-.09A1.65 1.65 0 0 0 9 19.4a1.65 1.65 0 0 0-1.82.33l-.06.06a2 2 0 0 1-2.83-2.83l.06-.06A1.65 1.65 0 0 0 4.68 15a1.65 1.65 0 0 0-1.51-1H3a2 2 0 0 1 0-4h.09A1.65 1.65 0 0 0 4.6 9a1.65 1.65 0 0 0-.33-1.82l-.06-.06a2 2 0 0 1 2.83-2.83l.06.06A1.65 1.65 0 0 0 9 4.68a1.65 1.65 0 0 0 1-1.51V3a2 2 0 0 1 4 0v.09a1.65 1.65 0 0 0 1 1.51 1.65 1.65 0 0 0 1.82-.33l.06-.06a2 2 0 0 1 2.83 2.83l-.06.06A1.65 1.65 0 0 0 19.4 9a1.65 1.65 0 0 0 1.51 1H21a2 2 0 0 1 0 4h-.09a1.65 1.65 0 0 0-1.51 1z"/>
          </svg>
        </button>
        <SettingsPanel
          show={showSettings} onClose={()=>setShowSettings(false)}
          settings={{themeIdx,bgImage,bgList,widgets,fontSize}}
          onChange={handleChange} fileRef={fileRef} onUpload={handleUpload}
        />
      </div>

      <div style={{maxWidth:700,margin:"0 auto",display:"flex",flexDirection:"column",gap:18,paddingTop:8,position:"relative",zIndex:1}}>
        <Clock fontSize={fontSize}/>
        <SearchBar fontSize={fontSize}/>
        {(widgets.weather||widgets.todo)&&(
          <div style={{display:"flex",gap:16,flexWrap:"wrap"}}>
            {widgets.weather&&<WeatherCard fontSize={fontSize}/>}
            {widgets.todo&&<TodoCard fontSize={fontSize}/>}
          </div>
        )}
        {widgets.stock&&<StockSection fontSize={fontSize}/>}
        {widgets.news&&<NewsSection fontSize={fontSize}/>}
        <div style={{textAlign:"center",fontSize:12,color:"#c7d2fe",paddingBottom:4}}>✨ Claude AI가 실시간으로 날씨와 뉴스를 검색합니다</div>
      </div>
    </div>
  );
}