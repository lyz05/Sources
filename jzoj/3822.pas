var i,j,m,n,k:longint;
    a:array[1..1000000] of longint;
    ans:qword;
begin
	//assign(input,'3822.in');reset(input);

	k:=0;
        readln(n);
        for i:=1 to n do begin
		read(a[i]);
		if a[i]=0 then inc(k);
	end;
	for i:=1 to n do begin
		if a[i]=1 then inc(ans,k) else dec(k);
	end;
	writeln(ans);
	//close(input);
end.
