uses	math;
const	maxn=100000;
var	i,j,k,m,n,maxx:longint;
	a,ans:array[1..maxn] of longint;
function gcd(x,y:longint):longint;
var	t:longint;
begin
	while y<>0 do begin
		t:=x mod y;
		x:=y;
		y:=t;
	end;
	exit(x);
end;
begin
	assign(input,'1334.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
	for i:=1 to n do begin
		read(a[i]);
		ans[i]:=1;
	end;
	
	for i:=1 to n-1 do begin
		for j:=i+1 to n do begin
			if gcd(a[i],a[j])>1 then begin
				ans[j]:=max(ans[j],ans[i]+1);
			end;
		end;
	end;
	maxx:=0;
	for i:=1 to n do 
		if ans[i]>maxx then maxx:=ans[i];
	writeln(maxx);
end.
