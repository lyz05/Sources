const max=72;
var	i,j,last,sy:longint;
	f,sum,one:array[0..max] of int64;
	p:array[0..max] of boolean;
     n,ans,js,x,k,m:int64;
procedure work(n,qz:int64);
var i:longint;
begin
	if n=0 then begin
		for i:=1 to sy do
			if p[i] then inc(js);
		exit;
	end;
	dec(n);
	inc(js,qz);
	for i:=1 to max do begin
		if sum[i]>n then begin
			dec(n,sum[i-1]);
			inc(js,one[i-1]+sum[i-1]*qz);
			break;
		end;
	end;
	p[last-i+1]:=true;
	work(n,qz+1);
end;
procedure print;
begin
	writeln(js);
	halt;
end;
begin
	f[1]:=1;
	f[2]:=1;
	sum[1]:=1;
	sum[2]:=2;
	one[1]:=1;
	one[2]:=2;
	for i:=3 to max do begin
		f[i]:=f[i-1]+f[i-2];
		sum[i]:=sum[i-1]+f[i];
		one[i]:=one[i-1]+one[i-2]+f[i];
	end;
	readln(n);
	ans:=0;
	for i:=1 to max do begin
		if ans+i*f[i]>=n then begin
			inc(js,one[i-1]);
			break;
		end;
		inc(ans,i*f[i]);
	end;
	dec(n,ans);
	last:=i;
	sy:=n mod i;
	p[1]:=true;
	work(n div i,1);
	print;
end.
