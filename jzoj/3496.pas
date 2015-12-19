uses	math;
const	maxn=100000;maxm=maxn;
var	i,j,k,m,n,x,y,z:longint;
	w:array[1..maxn] of longint;
	a:array[1..maxm,1..3] of longint;
	tmp,ans:int64;
begin
	assign(input,'3496.in');reset(input);
	//assign(input,'.in');rewrite(output);

	readln(n);
	for i:=1 to n do read(w[i]);
	readln(m);
	for i:=1 to m do read(a[i,1],a[i,2],a[i,3]);
	
	for i:=1 to m do begin
		inc(w[a[i,1]],a[i,3]);
		inc(w[a[i,2]],a[i,3]);
	end;
	ans:=0;
	for i:=1 to n do begin
		if w[i]>0 then inc(ans,w[i]);
	end;
	for i:=1 to m do dec(ans,a[i,3]);
	writeln(ans);

	//close(input);close(output);
end.
