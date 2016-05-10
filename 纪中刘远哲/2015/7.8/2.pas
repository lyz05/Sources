uses	math;
const	maxn=100;
var	i,j,k,m,n,max,maxk,ans,dep:longint;
	map:array[1..maxn,-1..maxn] of longint;
	list:array[1..2*maxn] of longint;
begin
	assign(input,'2.in');reset(input);
	readln(n,m);
	for i:=1 to n do begin
		read(k);
		for j:=1 to k do read(map[i][j]);
		map[i][0]:=k;
	end;

	for i:=1 to n do begin
		list[i]:=1;
		list[n+i]:=map[i,0];
	end;
	while m>0 do begin
		max:=0;maxk:=0;
		for i:=1 to 2*n do begin
			if i>n then dep:=i-n else dep:=i;
			if map[dep,list[i]]>max then begin
				max:=map[dep,list[i]];
				maxk:=i;
			end;
		end;
		inc(ans,max);
		i:=maxk;
		if maxk<=n then begin
			inc(list[i]);
			if list[i]=list[n+i] then list[i]:=-1;
			if list[n+i]=-1 then list[i]:=-1;	
		end else begin
			dec(list[i]);
			if list[i]=list[i-n] then list[i]:=-1;
			if list[i-n]=-1 then list[i]:=-1;
		end;
		dec(m);
	end;
	writeln(ans);
end.
