const	maxn=1105;mo=1000000009;
var	i,j,n,k:longint;
	ans,t,tmp:int64;
	a:array[1..maxn] of int64;
	c:array[0..maxn,0..maxn] of int64;
	p:array[2..maxn] of boolean;
begin
	readln(n,k);
	c[0,0]:=1;c[1,0]:=1;c[1,1]:=1;
	for i:=2 to n+k-1 do begin
		c[i,0]:=1;
		for j:=1 to i do 
			c[i,j]:=(c[i-1,j]+c[i-1,j-1]) mod mo;
	end;
	for i:=2 to n do a[i]:=c[n+k-1-i,k-1];//k-1
	
	ans:=1;
	fillchar(p,sizeof(p),true);
	for i:=2 to n do begin
		if p[i] then begin
			t:=a[i];
			for j:=2 to n div i do begin
				tmp:=i*j;
				while tmp mod i = 0 do begin
					t:=(t+a[i*j]) mod mo;
					tmp:=tmp div i;
				end;
				p[i*j]:=false;
			end;
			ans:=ans*(t+1) mod mo;
		end;
	end;
	writeln(ans);
end.
