const maxr=75;maxc=maxr;
var 	i,j,k,m,n,l,r,mid,ans:longint;
	map:array[1..maxr,1..maxc] of integer;
	sum:array[1..maxr,1..maxc] of longint;
        s:string;
function get(x1,y1,x2,y2:longint):longint;
begin
	get:=sum[x2,y2]-sum[x2,y1-1]-sum[x1-1,y2]+sum[x1-1,y1-1];
end;
function check1(x,x1,x2,x3:longint):boolean;
var	ret,last,r:longint;
begin
	ret:=0;last:=1;
	for r:=1 to m do begin
		if (get(1,last,x1,r)>=x) and (get(x1+1,last,x2,r)>=x) and (get(x2+1,last,x3,r)>=x) and (get(x3+1,last,n,r)>=x) then begin
			inc(ret);
			last:=r+1;
		end;
	end;
	if ret>=4 then exit(true) else exit(false);
end;
function check(x:longint):boolean;
var 	i,j,k:longint;
begin
	for i:=1 to n-1 do
		for j:=i+1 to n-1 do
			for k:=j+1 to n-1 do
				if check1(x,i,j,k) then
                                        exit(true);
	exit(false);
end;
begin
	//assign(input,'cake.in');reset(input);
	//assign(output,'cake.out');rewrite(output);

	readln(n,m);
	for i:=1 to n do begin
                readln(s);
		for j:=1 to m do begin
			map[i,j]:=ord(s[j])-ord('0');
			sum[i,j]:=sum[i-1,j]+sum[i,j-1]-sum[i-1,j-1]+map[i,j];
		end;
	end;

	l:=0;r:=5625;
	while (l<=r) do begin
		mid:=(l+r) >> 1;
		if (check(mid)) then begin
			ans:=mid;
			l:=mid+1;
		end else r:=mid-1;
	end;
	writeln(ans);

	//close(input);close(output);
end.
