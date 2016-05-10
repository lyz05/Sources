uses	math;
const	maxn=100000;mo=10009;
var	i,j,k,m,n,q,ans,maxx,maxy,tot,kk:longint;
	v,r,xx,yy:array[0..maxn] of longint;
function pd(x,y:longint):boolean;
var	i:longint;
begin
	for i:=0 to n do
		if (v[i]>x) and (r[i]>y) then exit(true);
	exit(false);
end;
begin
	readln(n,kk);
	for i:=1 to n do begin
		readln(v[i],r[i]);
		if v[i]>maxx then maxx:=v[i];
		if r[i]>maxy then maxy:=r[i];
	end;
	readln(q);
	for i:=1 to q do begin
		readln(v[0],r[0]);
		ans:=0;
		for j:=1 to max(v[0],maxx) do
                        for k:=1 to max(r[0],maxy) do
                                if pd(j,k) then begin
					inc(ans);
					xx[ans]:=j;
					yy[ans]:=k;
				end;
		tot:=ans;
		if kk=2 then begin
                        ans:=0;
			for j:=1 to tot-1 do
				for k:=j+1 to tot do begin
					if (xx[j]<>xx[k]) and (yy[j]<>yy[k]) then ans:=(ans+1) mod mo;
				end;
		end;
                writeln(ans mod mo);
	end;
end.
