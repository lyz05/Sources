var
        f1,f2,a,b,c,d,e,g:array[0..1000000] of longint;
        h,next,go:array[0..2000000] of longint;
        i,j,k,l,t,n,m,tot:longint;
function getfather(x:longint):longint;
begin
        if f2[x]=x then exit(x);
        getfather:=getfather(f2[x]);
        f2[x]:=getfather;
end;
procedure add(x,y:longint);
begin
        inc(tot);
        go[tot]:=y;
        next[tot]:=h[x];
        h[x]:=tot;
end;
procedure dfs(x,y:longint);
var
        t:longint;
begin
        f1[x]:=y;
        d[x]:=d[y]+1;
        t:=h[x];
        while t<>0 do
        begin
                if go[t]<>y then
                begin
                        dfs(go[t],x);
                        e[go[t]]:=(t+1) div 2;
                end;
                t:=next[t];
        end;
end;
procedure dark(x,y,z:longint);
begin
        x:=getfather(x);
        y:=getfather(y);
        while x<>y do
        begin
                if d[x]<d[y] then
                begin
                        x:=x xor y;
                        y:=x xor y;
                        x:=x xor y;
                end;
                if b[x]<>m+1 then x:=f2[x]
                else
                begin
                        f2[x]:=f2[f1[x]];
                        b[x]:=z;
                        x:=f2[x];
                end;
        end;
end;
begin
        readln(n,m);
        fillchar(a,sizeof(a),255);
        for i:=1 to n-1 do
        begin
                readln(j,k);
                add(j,k);
                add(k,j);
        end;
        for i:=1 to n do
        begin
                f2[i]:=i;
                b[i]:=m+1;
        end;
        dfs(1,1);
        for i:=1 to m do
        begin
                read(t);
                if t=2 then
                begin
                        readln(j,k);
                        dark(j,k,i);
                end
                else readln(a[i]);
        end;
        for i:=1 to n do inc(c[b[i]]);
        for i:=1 to m+1 do c[i]:=c[i-1]+c[i];
        for i:=1 to n do
        begin
                g[c[b[i]]]:=i;
                dec(c[b[i]]);
                f2[i]:=i;
        end;
        l:=n;
        for i:=m+1 downto 1 do
        begin
                if a[i]<>-1 then a[i]:=e[getfather(a[i])]
                else
                begin
                        while(l>0)and(b[g[l]]=i)do
                        begin
                                f2[g[l]]:=f2[f1[g[l]]];
                                dec(l);
                        end;
                end;
        end;
        for i:=1 to m do
                if a[i]<>-1 then writeln(a[i]);
end.
