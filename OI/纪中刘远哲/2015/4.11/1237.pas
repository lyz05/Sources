uses	math;
const	maxn=2000;maxm=2000;
var	i,j,k,m,n,ans,low:longint;
	up:array[0..maxn,0..maxm] of longint;
	s:ansistring;		//change
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to n do begin
		readln(s);
		for j:=1 to m do begin
			if s[j]='X' then up[i,j]:=0 else 
				up[i,j]:=up[i-1,j]+1;
		end;
	end;

	ans:=0;
	for i:=n downto 1 do 
		for j:=1 to m do begin
			low:=up[i,j];
			for k:=j to m do begin
				low:=min(low,up[i,k]);
				if low=0 then break;
				ans:=max(ans,(k-j+1+low)*2);
			end;
		end;
	writeln(ans-1);
end.
