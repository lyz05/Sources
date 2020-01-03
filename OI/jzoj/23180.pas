var s,f,g:array[0..1000000]of int64;
    q:array[0..1000000]of longint;
    st,en,i,j,n:longint;
    a,b,c:int64;
function xl(i,j:longint):extended;
begin
    exit((g[j]-g[i])/(s[j]-s[i]));
end;
begin
assign(input,'23180.in');reset(input);
    readln(n);
    readln(a,b,c);
    for i:=1 to n do
    begin
        read(s[i]);
        inc(s[i],s[i-1]);
    end;
    st:=0;en:=0;q[0]:=0;g[0]:=0;
    for i:=1 to n do
    begin
        while (st<en)and(xl(q[st],q[st+1])>=2*a*s[i]) do inc(st);
        j:=q[st];
        f[i]:=f[j]+a*sqr(s[i]-s[j])+b*(s[i]-s[j])+c;
        g[i]:=a*sqr(s[i])-b*s[i]+f[i];
        while (en>st)and(xl(q[en],i)>xl(q[en-1],q[en])) do dec(en);
        inc(en);
        q[en]:=i;
    end;
    writeln(f[n]);
end.
