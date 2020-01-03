uses	math;
const	maxn=2000+5;maxm=maxn;
var	i,j,k,m,n,d,ans,head,tail:longint;
	a,b:array[1..maxn] of longint;
	f:array[0..maxm,1..maxn] of longint;
	q:array[0..maxn] of longint;
begin
	assign(input,'1773.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n,d,m);
	for i:=1 to n do begin
		read(a[i],b[i]);
	end;
	ans:=0;f[0,1]:=a[1];
	
	for i:=1 to m do begin
		head:=1;tail:=0;
		for j:=1 to n do begin
			while (head<=tail) and (b[j]-b[q[head]]>d) do inc(head);
			if (head>tail) then f[i,j]:=0 else f[i,j]:=f[i-1,q[head]]+a[j];
			while (head<=tail) and (f[i-1][q[tail]]<f[i-1][j]) do dec(tail);
			inc(tail);
			q[tail]:=j;
			if i=m then ans:=max(ans,f[i,j]);
		end;
	end;
	writeln(ans);
	//close(input);close(output);
end.
