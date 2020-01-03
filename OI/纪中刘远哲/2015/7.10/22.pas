uses	math;
type	node=record
		min,max:longint;
	end;
const	maxn=100;
var	i,j,k,m,n:longint;
	min1,min2,max1,max2:longint;
	ans:longint;
	map:array[1..maxn,1..maxn] of longint;
	f:array[0..maxn,0..maxn] of node;
begin
	assign(input,'2.in');reset(input);
	readln(n,m);
	for i:=1 to n do 
		for j:=1 to m do read(map[i,j]);
	
	//for i:=1 to n do f[i][0].min:=maxlongint>>1;
	//for j:=1 to m do f[0][j].min:=maxlongint>>1;
	f[1,1].min:=map[1,1];
	f[1,1].max:=map[1,1];
	for i:=1 to n do 
		for j:=1 to m do begin
			if (i=1) and (j=1) then continue;
			min1:=0;min2:=0;
			max1:=maxlongint>>1;max2:=maxlongint>>1;
			if j>1 then begin
			min1:=min(f[i,j-1].min,map[i,j]);
			max1:=max(f[i,j-1].max,map[i,j]);
			end;
			if i>1 then begin
			min2:=min(f[i-1,j].min,map[i,j]);
			max2:=max(f[i-1,j].max,map[i,j]);
			end;
			if max1-min1<max2-min2 then begin
				f[i][j].min:=min1;f[i][j].max:=max1;
			end else begin
				f[i][j].min:=min2;f[i][j].max:=max2;
			end;
		end;
	ans:=f[n][m].max-f[n][m].min;
	writeln(ans);
end.
