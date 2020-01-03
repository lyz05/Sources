uses	math;
const	maxn=3000;oo=1000000000;
var	i,j,k,m,n,l,cnt1,cnt2,kk,maxx:longint;
	a:array[1..maxn,1..3] of longint;
	ans:double;
	s:string;
function cut(x,y:longint):double;
var	t1,t2,i:longint;
begin
	if x>y then exit(cnt1/cnt2);
	t1:=cnt1;
	t2:=cnt2;
	for i:=x to y do begin
		dec(t1,a[i,1]);
		dec(t2,a[i,2]);
	end;
	exit(t1/t2);
end;
begin
	assign(input,'escape.in');reset(input);
	assign(output,'escape.out');rewrite(output);

	cnt1:=0;cnt2:=0;
	readln(n,l);
	for i:=1 to n do begin
		readln(a[i,1],a[i,2],a[i,3]);
		inc(cnt1,a[i,1]);
		inc(cnt2,a[i,2]);
	end;

	ans:=cnt1/cnt2;
	for i:=0 to n-1 do begin
		maxx:=0;
		for j:=i+1 to min(i+l,n) do begin
			if a[j,3]>=maxx then begin
				maxx:=a[j,3];
				kk:=j;
			end;
		end;
		ans:=max(ans,cut(i+1,kk-1));
	end;
	
	ans:=round(ans*oo)/oo;
	str(ans,s);
	for i:=2 to 12 do write(s[i]);
	write('e');
	for i:=20 to 23 do write(s[i]);
	writeln;
	close(input);close(output);
end.
