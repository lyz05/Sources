uses	math;
const	oo=maxlongint;maxn=1000+5;
var	i,m,n,head,tail,ans:longint;
	a,f,q:array[1..maxn] of longint;
begin
	assign(input,'1771.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n,m);
	for i:=1 to n do read(a[i]);
	
	head:=1;tail:=m;
	for i:=1 to n do begin
		//f[i]:=min(f[k])+a[i];(i-m<=k<=i-1)
		while (head<=tail) and (q[head]<i-m) do inc(head);
		f[i]:=f[q[head]]+a[i];
		while (head<=tail) and (f[q[tail]]>f[i]) do dec(tail);
		inc(tail);
		q[tail]:=i;
	end;
	
	ans:=oo;
	for i:=n downto n-m+1 do 
		ans:=min(ans,f[i]);
	writeln(ans);
	//close(input);close(output);
end.
