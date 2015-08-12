const maxn=100000; wzd=trunc(ln(maxn)/ln(2));
type
        point=^node;
        node=
        record
                x:longint;
                next:point;
        end;
var
        f,g:array[1..maxn,0..wzd]of longint;
        d,first:array[1..maxn]of longint;
        p:array[1..maxn,1..2]of longint;
        h:array[1..maxn]of point;
        t:array[1..maxn*2]of longint;
        rmq:array[1..maxn*2,0..wzd+1]of longint;
        u,v,i,j,x,y,fa,ans,n,q,k,l,r,uu:longint;
        tt,le:array[0..6]of longint;
procedure inse(x,y:longint);
var
        q:point;
begin
        new(q);
        q^.x:=y;
        q^.next:=h[x];
        h[x]:=q;
end;
procedure dfs(x:longint);
var
        q:point;
begin
        inc(k);
        t[k]:=x;
        first[x]:=k;
        q:=h[x];
        while q<>nil do
        begin
                if x>q^.x then
                begin
                        p[q^.x,1]:=p[x,1];
                        p[q^.x,2]:=q^.x;
                end
                else
                begin
                        p[q^.x,1]:=q^.x;
                        p[q^.x,2]:=p[x,2];
                end;
                d[q^.x]:=d[x]+1;
                dfs(q^.x);
                inc(k);
                t[k]:=x;
                q:=q^.next;
        end;
end;
function max(x,y:longint):longint;
begin
        if x>y then exit(x)else exit(y);
end;
function ask(l,r:longint):longint;
var
        x:longint;
begin
        x:=trunc(ln(r-l+1)/ln(2));
        if d[rmq[l,x]]<d[rmq[r-(1<<X)+1,x]] then exit(rmq[l,x])
        else exit(rmq[r-(1<<x)+1,x]);
end;
procedure calc(x,fa:longint);
begin
        if x=fa then
        begin
                inc(k);
                tt[k]:=x;
                inc(k);
                tt[k]:=x;
                exit;
        end;
        for i:=trunc(ln(n)/ln(2))downto 0 do
        begin
                if d[f[f[x,i],1]]>d[fa] then
                begin
                        ans:=max(ans,g[x,i]);
                        x:=f[x,i];
                end;
        end;
        if d[f[x,1]]>d[fa] then
        begin
                ans:=max(d[x]-d[f[x,1]]+1,ans);
                x:=f[x,0];
        end;
        ans:=max(ans,d[x]-d[fa]+1);
        inc(k);
        tt[k]:=x;
        x:=f[x,0];
        if d[x]<d[fa] then x:=fa;
        inc(k);
        tt[k]:=x;
end;
procedure prepare;
begin
        uu:=trunc(ln(n)/ln(2));
        for i:=1 to n do
                if p[i,1]=i then f[i,0]:=p[i,2]
                else f[i,0]:=p[i,1];
        for j:=1 to max(uu,1) do
                for i:=1 to n do
                f[i,j]:=f[f[i,j-1],j-1];
        for i:=1 to n do g[i,0]:=max(d[i]-d[f[i,1]]+1,d[f[i,0]]-d[f[f[i,0],1]]+1);
        for j:=1 to max(uu,1) do
                for i:=1 to n do
                g[i,j]:=max(g[i,j-1],g[f[i,j-1],j-1]);
        for i:=1 to k do rmq[i,0]:=t[i];
        for j:=1 to trunc(ln(k)/ln(2)) do
                for i:=1 to k-(1<<j)+1 do
                if d[rmq[i,j-1]]<d[rmq[i+(1<<(j-1)),j-1]] then
                rmq[i,j]:=rmq[i,j-1]
                else rmq[i,j]:=rmq[i+(1<<(j-1)),j-1];
end;
procedure init;
begin
        readln(n);
        for i:=2 to n do
        begin
                readln(x);
                inse(x,i);
        end;
end;
begin
        init;
        p[1,1]:=1;
        p[1,2]:=1;
        dfs(1);
        prepare;
        readln(q);
        ans:=0;
        for q:=1 to q do
        begin
                readln(u,v);
                u:=u xor ans;
                v:=v xor ans;
                if first[u]>first[v] then
                begin
                        u:=u xor v;
                        v:=u xor v;
                        u:=u xor v;
                end;
                fa:=ask(first[u],first[v]);
                if u=v then
                begin
                        ans:=1;
                        writeln(ans);
                        continue;
                end;
                l:=0;
                k:=0;
                ans:=1;
                calc(u,fa);
                k:=3;
                tt[k]:=fa;
                calc(v,fa);
                k:=0;
                tt[5]:=tt[5] xor tt[4];
                tt[4]:=tt[4] xor tt[5];
                tt[5]:=tt[5] xor tt[4];
                for j:=1 to 5 do
                if (j=1)or(tt[j]<>tt[j-1])then
                begin
                        inc(k);
                        tt[k]:=tt[j];
                end;
                x:=0;
                fillchar(le,sizeof(le),0);
                for j:=1 to k-1 do le[j]:=abs(d[tt[j]]-d[tt[j+1]])+1;
                for j:=1 to k do
                if tt[j]=fa then
                begin
                        x:=j;
                        break;
                end;
                for j:=1 to k-1 do ans:=max(ans,le[j]);
                if (x=1)or(x=k)then ans:=max(ans,le[1]+le[2]-1)
                else
                begin
                        ans:=max(ans,le[x]+le[x-1]-1);

                if ((tt[x-1]<fa)and(fa<tt[x+1]))or
                ((tt[x-1]>fa)and(fa>tt[x+1]))then
                begin
                        if x>2 then ans:=max(ans,le[x-2]+le[x]+le[x-1]-2);
                        if x<4 then ans:=max(ans,le[x-1]+le[x]+le[x+1]-2);
                end;
                end;
                writeln(ans);
        end;
        close(input);
        close(output);
end.
