uses	math;
const	maxn=2000;
var	i,j,k,n,ans:longint;
	a:array[1..maxn,1..2] of longint;
	maxj:array[0..maxn] of longint;
	f:array[0..maxn,0..maxn] of longint;
	s:string;
begin
	readln(n);
	for i:=1 to n-1 do begin
		readln(s);
		if copy(s,1,1)='d' then a[i,1]:=1 else a[i,1]:=2;
		val(copy(s,3,length(s)-3+1),a[i,2]);
		maxj[i]:=maxj[i-1];
		if a[i,1]=1 then inc(maxj[i],1) else maxj[i]:=min(a[i,2]-1,maxj[i-1]);
	end;
        maxj[n-1]:=maxj[n-2];
	for i:=1 to n-1 do begin
		for j:=1 to maxj[i] do begin
			if a[i,1]=1 then
				f[i,j]:=max(f[i-1,j-1]+a[i,2],f[i-1,j])
			else begin
				if (j<a[i,2]) or (i=n-1) then
					f[i,j]:=f[i-1,j];
			end;
		end;
	end;
	for i:=a[n-1,2] to maxj[n-1] do ans:=max(ans,f[n-1,i]);
	if ans=0 then writeln(-1) else writeln(ans);
end.
