var
	n,i,x,head,tail,a,b,c:longint;
	f,g,s:array[0..1000001]of int64;
	que:array[0..1000001]of longint;
function t(j1,j2:int64):extended;
begin
	exit((g[j2]-g[j1])/(s[j2]-s[j1]));
end;

begin
	assign(input,'2318.in');reset(input);

	readln(n);
	readln(a,b,c);
	for i:=1 to n do
	begin
		read(x);
		s[i]:=s[i-1]+x;
	end;
	f[0]:=0;
	head:=1;
	tail:=1;
	que[1]:=0;
	for i:=1 to n do	
	begin		
		while (head<tail)and(t(que[head],que[head+1])>=2*a*s[i]) do inc(head);
		f[i]:=(f[que[head]])+int64(a)*(s[i]-s[que[head]])*(s[i]-s[que[head]])+int64(b)*(s[i]-s[que[head]])+int64(c);
		g[i]:=f[i]+int64(a)*s[i]*s[i]-int64(b)*s[i];
		while (head<tail)and(t(que[tail-1],que[tail])<t(que[tail],i)) do dec(tail);
		inc(tail);
		que[tail]:=i;
	end;
	writeln(f[n]);
end.
