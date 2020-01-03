const
        maxn=105;
var
        n,m,i,j,k,l,data,tmp,ans,f0,f1:longint;
        h:array[0..maxn]of longint;
        f:array[0..maxn,0..maxn,0..260,0..9]of longint;
        flag:array[0..maxn]of boolean;
        have:array[0..9]of boolean;
function min(x,y:longint):longint;
begin
        if x<y then exit(x) else exit(y);
end;
procedure update(var f1,f2:longint);
begin
        if f2<f1 then f1:=f2;
end;
begin
                readln(n,m);
                for i:=1 to n do
                begin
                        read(h[i]);
				    h[i]:=h[i]-25;
                end;
                readln;
                fillchar(have,sizeof(have),false);
                fillchar(flag,sizeof(flag),false);
                for i:=n downto 1 do
                begin
                        if have[h[i]] then flag[i]:=true;
                        have[h[i]]:=true;
                end;
                fillchar(f,sizeof(f),50);
			 data:=f[0][0][0][0];
                f[0][0][0][8]:=0;
                for i:=0 to n-1 do
                begin
                        for j:=0 to m do
                        begin
                                for k:=0 to (1 shl 8)-1 do
                                begin
                                        for l:=0 to 8 do
                                        if f[i][j][k][l]<>data then
                                        begin
                                                f0:=f[i][j][k][l];
                                                f1:=f0+1;
                                                //no pick
                                                if h[i+1]=l then update(f[i+1][j][k or (1 shl h[i+1])][h[i+1]],f0)
                                                else update(f[i+1][j][k or (1 shl h[i+1])][h[i+1]],f1);
                                                //pick and k have
                                                if k and (1 shl h[i+1])=1 shl h[i+1] then update(f[i+1][j+1][k][l],f0)
                                                else begin
                                                //pick and let it to the first
                                                update(f[i+1][j+1][k or (1 shl h[i+1])][l],f1);
                                                //pick and let it to right
                                                if flag[i+1] then
                                                update(f[i+1][j+1][k][l],f0);
                                                end;
                                        end;
                                end;
                        end;
                end;
                ans:=data;
                for j:=0 to m do
                        for k:=0 to (1 shl 8)-1 do
                                for l:=0 to 8 do
                                        if f[n][j][k][l]<ans then ans:=f[n][j][k][l];
                writeln(ans);
end.
