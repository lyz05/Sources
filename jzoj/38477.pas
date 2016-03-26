uses math;
const
        mo=10086;
type
        matrix=array[0..70,1..70] of longint;
var
        n,m,t,i,j,k,u,v,ans:longint;
        f,map,temp:matrix;
        h:array[1..70] of longint;
procedure mult(a,b:matrix;var c:matrix);
var
        i,j,k:longint;
begin
        fillchar(c,sizeof(c),0);
        for i:=1 to n do
                for j:=1 to n do
                        for k:=1 to n do
                                c[i,j]:=(c[i,j]+a[i,k]*b[k,j]) mod mo;
end;
begin
        read(n,m,t);
        for i:=1 to n do
        begin
                map[i,i]:=1;
                read(h[i]);
        end;
        for i:=1 to m do
        begin
                read(u,v);
                inc(map[u,v]);
        end;
	   
	   
        f[0,1]:=1;
        for i:=1 to min(t,70) do
                for j:=1 to n do
                        for k:=1 to n do
                                if (map[k,j]>0)and(i>=h[j]) then
                                        f[i,j]:=(f[i,j]+f[i-1,k]*map[k,j]) mod mo;
        if t<=70 then writeln(f[t,n])
        else
        begin
                t:=t-70;
                for i:=1 to n do temp[i,i]:=1;
                while t>0 do
                begin
                        if t mod 2=1 then mult(temp,map,temp);
                        mult(map,map,map);
                        t:=t div 2;
                end;
                for j:=1 to n do
                        ans:=(ans+f[70,j]*temp[j,n]) mod mo;
                writeln(ans);
        end;
end.
