var	i,j,k,m,n:longint;
	x,now,last,a,b,c,d:real;
function work(x:real):real;
var	i,j,k:real;
begin
	k:=x;j:=k*x;i:=j*x;
	exit(a*i+b*j+c*k+d);
end;
begin
	readln(a,b,c,d);
	n:=0;
	for i:=-10000 to 10000 do begin
		x:=i/100;
		now:=work(x);
		if (now=0) then begin
			write(x:0:2,' ');
			inc(n);
		end;
		if ((now>0) and (last<0)) or ((now<0) and (last>0))
		then begin
			inc(n);
			if abs(now)<abs(last) then 
				write(x:0:2,' ')
			else
				write(x-0.01:0:2,' ');
		end;
		last:=now;
		if n=3 then exit;
	end;

end.
