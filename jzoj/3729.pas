var     t,i:longint;
        ans,n,x,xl,z,ans1:int64;
begin

	readln(n,z);
	ans1:=0;
	if z>n then begin
		ans1:=ans1+n*(z-n);
                z:=n;
	end;
	ans:=0;
	for i:=1 to trunc(sqrt(n)) do begin
		x:=n div i;
		inc(ans,n div i*i);
		if i<>1 then inc(ans,((xl-x)*(xl+x+1)) div 2*(i-1));
		xl:=x;
	end;
        ans:=n*n-ans;
	ans:=ans+ans1;
        writeln(ans);
end.
