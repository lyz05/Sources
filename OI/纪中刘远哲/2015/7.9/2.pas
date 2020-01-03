uses	math;
const	maxn=100000+5;
var	i,j,k,n,maxx,minn:longint;
	a,b:array[1..maxn] of longint;
	tmp,ans:int64;
begin
	assign(input,'2.in');reset(input);

	minn:=maxlongint>>1;maxx:=0;
	readln(n);
	for i:=1 to n do begin
		readln(a[i],b[i]);
		minn:=min(minn,a[i]);
		maxx:=max(maxx,b[i]);
	end;
	ans:=0;
	for i:=minn to maxx do begin
		tmp:=0;
		for j:=1 to n do begin
			if i>b[j] then continue;
			if i<a[j] then inc(tmp,a[j])
			else inc(tmp,i);	
		end;
		if tmp>ans then begin
			k:=i;
			ans:=tmp;
		end;
	end;
	writeln(k,' ',ans);
end.
