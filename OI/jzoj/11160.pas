var	i,n,l:longint;
	c,s,f,q:array[-1..50000]of int64;
Procedure init;
begin
  readln(n,l);
  s[0]:=-1;
  For i:=1 to n do begin
    readln(c[i]);
    s[i]:=s[i-1]+c[i]+1;
  end;
end;

Function t(x,y:int64):extended;
begin
	exit((f[x]-f[y]+(s[x]+s[y]+2*l+2)*(s[x]-s[y]))/(2*(s[x]-s[y])));
end;   

Procedure main;
Var st,en:longint;
begin
  f[0]:=0;
  st:=1;en:=1;
  q[1]:=0;
  For i:=1 to n do begin
    while (st<en) and (t(q[st],q[st+1]) <= s[i]) do inc(st);
    f[i]:=f[q[st]]+sqr(s[i]-s[q[st]]-l-1);
    while(st<en)and (t(q[en-1],q[en])>=t(q[en],i))do dec(en);
    inc(en);q[en]:=i;
  end;
  writeln(f[n]);
end;
  
begin
	assign(input,'1116.in');reset(input);
  init;
  main;
end.


