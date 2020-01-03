const	maxn=20;
var	i,ii,n,cnt,l:longint;
	j,k,m:int64;
	flag:array[1..maxn] of boolean;
function jc(x:longint):int64;
var	i:longint;
begin
	jc:=1;
	for i:=2 to x do jc:=jc*i;
end;
begin
	readln(n,m);
	fillchar(flag,sizeof(flag),0);
	for i:=n downto 1 do begin
		j:=jc(i-1);
		k:=m div j;
		if m mod j=0 then l:=k else l:=k+1;
		cnt:=0;
		for ii:=1 to n do 
			if not flag[ii] then begin
				inc(cnt);
				if cnt=l then begin
					write(ii,' ');
					flag[ii]:=true;
					break;
				end;
			end;
		m:=m mod j;
		if m=0 then m:=j;
	end;
end.
