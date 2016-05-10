uses	math;
const	maxn=100000+5;
var	i,j,k,m,n,p,q,x,head,tail:longint;
	ans:int64;
	sum:array[0..maxn] of int64;
	que:array[0..maxn] of longint;
begin
	assign(input,'1772.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n,p,q);
	for i:=1 to n do begin
		read(x);
		sum[i]:=sum[i-1]+x;
	end;
	
	head:=1;tail:=0;
	ans:=-maxlongint div 2;
	for i:=p to n do begin
		while (head<=tail) and (sum[que[tail]]>=sum[i-p]) do dec(tail);
		inc(tail);
		que[tail]:=i-p;
		while (que[head]<i-q) do inc(head);
		ans := max(ans,sum[i]-sum[que[head]]);
	end;
	writeln(ans);
	//close(input);close(output);
end.
