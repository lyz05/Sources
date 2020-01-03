const	maxn=100000+10;
var	i,j,k,m,n:longint;
	a:array[0..maxn] of longint;
	s:array[0..maxn] of double;
function check(t:double):double;
var	i:longint;
	min,bi:double;
	flag:boolean;
begin
	for i:=1 to n do s[i]:=s[i-1]+(a[i]-t);
	min:=100000000;bi:=0;
	for i:=2 to n-1 do begin
		if (min>s[i-1]) then min:=s[i-1];
		if i=2 then bi:=s[i]-min;
		if bi<s[i]-min then bi:=s[i]-min;
	end;
	exit(s[n]-bi);
end;
procedure work;
var	d,l,r,mid:longint;
	ans:double;
begin
	d:=10000;l:=0;r:=100000000;
	while l<=r do begin
		mid:=(l+r)>>1;
		if check(mid/d)<0 then begin
			ans:=mid/d;
			r:=mid-1;
		end else l:=mid+1;
	end;
        writeln(ans:0:3);
end;
begin
	assign(input,'3960.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n);
	for i:=1 to n do readln(a[i]);
	work;
end.
