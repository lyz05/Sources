uses	math;
const	maxn=2000;maxm=2000;
var	i,j,k,m,n,len:longint;
	map,sum:array[0..maxn,0..maxm] of longint;
	tmp:array[0..maxm] of longint;
	s:ansistring;		//change
function calc(x1,y1,x2,y2:longint):longint;
begin
	calc:=sum[x2,y2]-sum[x1-1,y2]-sum[x2,y1-1]+sum[x1-1,y1-1];
end;
function work(x,y:longint):boolean;
var	i,j:longint;
begin
	for i:=1 to n-x+1 do begin
		for j:=1 to n-y+1 do begin
			if calc(i,j,i+x-1,j+y-1)=0 then begin
				exit(true);
				//writeln((x+y)<<1-1);
				//halt;
			end;
		end;
	end;
	exit(false);
end;
procedure half;
var	i,mid,l,r:longint;
	flag:boolean;
begin
	l:=2;r:=n+m;
	while l<=r do begin
		flag:=false;
		mid:=(l+r)>>1;
		len:=mid;
		for i:=max(1,len-n) to min(m,len-1) do begin
			if work(i,len-i) then begin
				flag:=true;
				break;
			end;
		end;
		if flag then l:=mid+1 else r:=mid-1;
	end;
	writeln(r<<1-1);
	halt;
end;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	fillchar(map,sizeof(map),0);
	for i:=1 to n do begin
		readln(s);
		tmp[0]:=0;
		for j:=1 to m do begin
			if s[j]='X' then map[i,j]:=1;
			tmp[j]:=tmp[j-1]+map[i,j];
			sum[i,j]:=sum[i-1,j]+tmp[j];
		end;
	end;
	half;
	{for len:=n+m downto 2 do begin
		for i:=max(1,len-n) to min(m,len-1) do begin
			work(i,len-i);
		end;
	end;}
	writeln(0);
end.
