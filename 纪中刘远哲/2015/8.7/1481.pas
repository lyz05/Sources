uses	math;
const	maxn=50000+10;oo=maxlongint;
var	i,n,l,r,mid,ans,t:longint;
	f,q,a:array[1..maxn] of longint;
function judge(x:longint):boolean;
var	i,head,tail:longint;
	ans:longint;
begin
	//f[i]=min(f[j])+a[i]，(i-x-1<=j<=i-1)
	head:=1;tail:=x+1;
	for i:=1 to n do begin
		while (head<=tail) and (q[head]<i-x-1) do inc(head);
		f[i]:=f[q[head]]+a[i];
		while (head<=tail) and (f[q[tail]]>f[i]) do dec(tail);
		inc(tail);
		q[tail]:=i;
	end;
	
	ans:=oo;
	for i:=n downto n-x do 
		ans:=min(ans,f[i]);
	exit(ans<=t);
end;
begin
	assign(input,'1481.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n,t);
	for i:=1 to n do read(a[i]);
	
	l:=1;r:=n;
	while (l<=r) do begin
		mid:=(l+r) div 2;
		if judge(mid) then begin
			r:=mid-1;
			ans:=mid;
		end else l:=mid+1;
	end;
	writeln(ans);
	//close(input);close(output);
end.
