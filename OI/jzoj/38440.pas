uses math;
type node=^dong;
dong=record
        y:longint;
        next:node;
end;
var
        a,f,d:array[0..100000] of longint;
        h:array[0..100000] of node;
        i,j,k,l,t,n,m,ans,x,y,sum:longint;
        p:node;
procedure add(x,y:longint);
begin
        new(p);
        p^.y:=y;
        p^.next:=h[x];
        h[x]:=p;
end;
procedure dfs(x:longint);
var
        p:node;
        sum:longint;
begin
        p:=h[x];
        sum:=0;
        while p<>nil do
        begin
                if d[p^.y]=0 then
                begin
                        d[p^.y]:=d[x]+1;
                        dfs(p^.y);
                        sum:=(sum+f[p^.y]) mod 10086;
                end;
                p:=p^.next;
        end;
        f[x]:=(sum+1) mod 10086;
        f[x]:=(f[x]*a[x]) mod 10086;
        ans:=(ans+f[x]) mod 10086;
        p:=h[x];
        while p<>nil do
        begin
                if d[p^.y]=d[x]+1 then
                begin
                        sum:=((sum-f[p^.y]) mod 10086+10086) mod 10086;
                        ans:=(ans+a[x]*f[p^.y] mod 10086 *sum) mod 10086;
                end;
                p:=p^.next;
        end;
end;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(a[i]);
                h[i]:=nil;
        end;
        for i:=1 to n-1 do
        begin
                readln(x,y);
                add(x,y);
                add(y,x);
        end;
        d[1]:=1;
        dfs(1);
        writeln(ans);
end.


