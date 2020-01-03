const maxn=101000;
type node=record
       son,ans:longint;
     end;
     arr=array[0..4]of longint;
var next,y,cost:array[0..maxn*2]of longint;
    g:array[0..maxn]of longint;
    f,fl,fr:array[0..maxn]of node;
    n,i,j,u,v,co,tt,answer:longint;
function max(a,b:longint):longint;
begin
    if a>b then exit(a);exit(b);
end;
procedure insert(i,j,v:longint);
begin
    inc(tt);
    next[tt]:=g[i];
    g[i]:=tt;
    y[tt]:=j;
    cost[tt]:=v;
end;
procedure dfs(r,fa:longint);
var  i,p:longint;
begin
    f[r].son:=0;
    f[r].ans:=0;
    p:=g[r];
    while p<>0 do begin
      i:=y[p];
      if i<>fa then begin
         dfs(i,r);
         f[r].ans:=max(f[r].ans,f[r].son+f[i].son+cost[p]);
         f[r].son:=max(f[r].son,f[i].son+cost[p]);
      end;
      p:=next[p];
    end;
end;
procedure ready(p,fa,f1,f2:longint;var bf1,bf2:longint);
var i,jf1,jf2:longint;
begin
    if p=0 then begin
       bf1:=0;bf2:=0;
       exit;
    end;
    i:=y[p];
    if i=fa then begin
       ready(next[p],fa,f1,f2,bf1,bf2);
       exit;
    end;
    fl[i].son:=f1;
    fl[i].ans:=f2;
    ready(next[p],fa,max(f1,f[i].son+cost[p]),max(f2,max(f[i].ans,f1+f[i].son+cost[p])),jf1,jf2);
    fr[i].son:=jf1;fr[i].ans:=jf2;
    bf1:=max(jf1,f[i].son+cost[p]);
    bf2:=max(jf2,max(f[i].ans,jf1+f[i].son+cost[p]));
end;
procedure dp(r,fa,f1,f2:longint);
var p,i,jf1,jf2,tmp:longint;
begin
    ready(g[r],fa,f1,f2,jf1,jf2);
    p:=g[r];
    while p<>0 do begin
      i:=y[p];
      if i<>fa then begin
         jf1:=max(fl[i].son,fr[i].son)+cost[p];
         jf2:=max(fl[i].son+fr[i].son,max(fl[i].ans,fr[i].ans));
	 tmp:=jf2+f[i].ans;
         answer:=max(answer,tmp);
         dp(i,r,jf1,jf2);
      end;
      p:=next[p];
    end;
end;
begin
	assign(input,'1737.in');reset(input);
    readln(n);
    tt:=0;
    for i:=1 to n-1 do begin
        readln(u,v,co);
        insert(u,v,co);
        insert(v,u,co);
    end;
    dfs(1,-1);
    dp(1,-1,0,0);
    writeln(answer);
end.
