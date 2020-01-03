uses	math;
const	maxn=200;maxm=maxn;maxk=maxn;
type	node=record
		val:longint;
		p:boolean;
	end;
var	i,j,k,m,n,kk:longint;
	map:array[1..maxn,1..maxm] of node;
	sum:array[1..maxn,0..maxn] of longint;
	f:array[0..maxm,0..maxk] of longint;
	ch:char;
begin
	assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m,kk);
	for i:=1 to n do begin
		for j:=1 to m do begin
			read(map[i,j].val);
			read(ch,ch);
			if ch='Y' then map[i,j].p:=true 
				else map[i,j].p:=false;
		end;
	end;
	fillchar(sum,sizeof(sum),0);
	fillchar(f,sizeof(f),0);
	for j:=1 to m do begin
		for i:=n downto 1 do begin
			sum[j,n-i+1]:=sum[j,n-i]+map[i,j].val;	
		end;
	end;
	for j:=1 to m do begin
		for i:=1 to min(kk,j*n) do begin
			for k:=0 to i do
				f[j,i]:=max(f[j,i],f[j-1,i-k]+sum[j,k]);
		end;
	end;
	writeln(f[m,kk]);
end.
