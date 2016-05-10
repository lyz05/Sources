uses	math;
const	maxk=200;maxn=200+2;maxm=200+2;oo=maxlongint;
var	i,j,k,m,n,x,y,x0,y0,s,ans:longint;
	map:array[0..maxn,0..maxm] of char;
	d,t:array[1..maxk] of longint;
	f:array[0..maxk,0..maxn,0..maxm] of longint;
begin
	assign(input,'2412.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n,m,x0,y0,k);
	for i:=1 to n do begin
		for j:=1 to m do 
			read(map[i,j]);
		readln;
	end;
	for i:=1 to k do begin
		readln(x,y,d[i]);
		t[i]:=y-x+1;
	end;
	
	
	for x:=1 to n do
	for y:=1 to m do f[0,x,y]:=-oo;
	f[0,x0,y0]:=0;
	
	ans:=0;
	for i:=1 to k do 
	for x:=1 to n do 
	for y:=1 to m do begin
		f[i,x,y]:=-oo;
		if map[x,y]='.' then begin
			for s:=1 to t[i] do begin
				case d[i] of 
					1:if (map[x+s,y]='.') and (x+s<=n) then
						f[i,x,y]:=max(f[i-1,x+s,y]+s,f[i,x,y]) else break;
					2:if (map[x-s,y]='.') and (x-s>0) then 
						f[i,x,y]:=max(f[i-1,x-s,y]+s,f[i,x,y]) else break;
					3:if (map[x,y+s]='.') and (y+s<=m) then 
						f[i,x,y]:=max(f[i-1,x,y+s]+s,f[i,x,y]) else break;
					4:if (map[x,y-s]='.') and (y-s>0) then
						f[i,x,y]:=max(f[i-1,x,y-s]+s,f[i,x,y]) else break;
				end;
			end;
			if i=k then ans:=max(ans,f[k,x,y]);
		end;
	end;
	
	writeln(ans);
	//close(input);close(output);
end.
