uses math;
const mo=1000000007;
var	i,j,k,m,n,cnt,tmp,kk:longint;
	c,f:array[0..150,0..150] of int64;
	s1,s2:string;
procedure prepar;
var i,j,k:longint;
begin
	c[0,0]:=1;
	for i:=1 to 110 do c[i,0]:=1;
	for i:=1 to 110 do
		for j:=1 to i do
			c[i,j]:=(c[i-1,j]+c[i-1,j-1]) mod mo;
end;
begin
	prepar;
	readln(n,kk,m);
	readln(s1);
	readln(s2);
	cnt:=0;
	for i:=1 to n do
		if s1[i]<>s2[i] then inc(cnt);
        fillchar(f,sizeof(f),255);
        f[cnt,0]:=1;
	for j:=0 to kk-1 do begin
		for i:=0 to n do
			if f[i,j]<>-1 then begin
				for k:=0 to min(i,m) do begin
					if (n-i)<(m-k) then continue;
					tmp:=i-k+m-k;
					if f[tmp,j+1]=-1 then begin
						f[tmp,j+1]:=f[i][j]*c[i,k] mod mo*c[n-i][m-k] mod mo;
					end else begin
						inc(f[tmp,j+1],f[i,j]*c[i,k] mod mo*c[n-i,m-k]);
						f[tmp,j+1]:=f[tmp,j+1] mod mo;
					end;
				end;
			end;
	end;
	if f[0,kk]<>-1 then writeln(f[0,kk]) else writeln('0');
end.
