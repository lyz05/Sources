uses math;
const	maxm=100+2;maxk=500+2;
var	i,j,k,n,m,x:longint;
	a:array[1..maxm] of longint;
	f:array[1..maxm,0..maxk] of int64;
function get1(x:longint):longint;
begin
	exit(x*(x+1)>>1);
end;
function get(n,k:longint):longint;
var t1,t2:longint;
begin
	inc(k);
	if k>=n then exit(n);
	t1:=n mod k;
	t2:=n div k;
	exit(t1*get1(t2+1)+(k-t1)*get1(t2));
end;
begin
        //assign(input,'data.in');reset(input);
	readln(n,m,k);
	for i:=1 to n do begin
		readln(x);
		inc(a[x]);
	end;

	fillchar(f,sizeof(f),127);
	for i:=0 to k do f[1,i]:=get(a[1],i);
	for i:=2 to m do
		for j:=0 to k do
			for k:=0 to j do begin
				f[i,j]:=min(f[i,j],f[i-1,j-k]+get(a[i],k));
			end;
	writeln(f[m,k]);

end.
