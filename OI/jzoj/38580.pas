var ti,t,n,i,j,s,p,q:longint;
    ans:int64;
    a:array[1..50000,1..2] of longint;
    b:array[1..50000] of boolean;
    c:array[0..50000] of longint;
function work(x:longint):int64;
var i,p,t:longint;
begin
    work:=x;
    p:=x;
    i:=1;
    t:=trunc(sqrt(p));
    while (c[i]<=t) and (i<=c[0]) do
    begin
        if x mod c[i]=0 then
        begin
            work:=work-work div c[i];
            while (x mod c[i]=0) do x:=x div c[i];
        end;
        inc(i);
    end;
    if x>1 then work:=work-work div x;
end;
procedure dfs(t,sum:longint; x,y:int64);
 var i:longint;
begin
    if t>s then
    begin
        if sum<=2 then inc(ans) else inc(ans,sum*x div y*sum div 2);
        exit;
    end;
    dfs(t+1,sum,x,y);
    for i:=1 to a[t,2] do
    begin
        sum:=sum*a[t,1];
        dfs(t+1,sum,x*(a[t,1]-1),y*a[t,1]);
    end;
end;
begin
    readln(t);
    for i:=2 to trunc(sqrt(1000000000)) do
    begin
        if b[i]=false then
        begin
            inc(c[0]);
            c[c[0]]:=i;
            j:=i+i;
            while (j<=trunc(sqrt(1000000000))) do
            begin
                b[j]:=true;
                j:=j+i;
            end;
        end;
    end;
    for ti:=1 to t do
    begin
        readln(n);
        p:=trunc(sqrt(n));
        s:=0;
        i:=1;
        while (c[i]<=p) do
        begin
            if (i<=c[0]) and (n mod c[i]=0) then
            begin
                inc(s);
                a[s,1]:=c[i];
                a[s,2]:=0;
                while (n mod c[i]=0) do
                begin
                    inc(a[s,2]);
                    n:=n div c[i];
                end;
            end;
            inc(i);
        end;
        if n<>1 then
        begin
            inc(s);
            a[s,1]:=n;
            a[s,2]:=1;
        end;
        ans:=0;
        dfs(1,1,1,1);
        writeln(ans);
    end;
end.
