var	i,j,k,m,n:longint;
	a1,b1,c1,a2,b2,c2,a3,b3,c3,tot1,tot2:longint;
	ok1,ok2:boolean;
function judge:boolean;
begin
	if (a1=b1) and (a2=b2) and (a3=b3) then exit(true)
		else exit(false);
end;
procedure sol_std(var src,tar,spa:longint;n:longint);
begin
	if (n<=0) or ok1 then exit;
	sol_std(src,spa,tar,n-1);
        if ok1 then exit;
        inc(tot1);
	inc(tar);dec(src);
	if tot1=k then begin
		ok1:=true;
		exit;
	end;
        sol_std(spa,tar,src,n-1);
        if ok1 then exit;
end;
procedure sol_w(var src,tar,spa:longint;n:longint);
begin
	if (n<=0) or ok2 then exit;
	sol_w(src,tar,spa,n-1);
        if ok2 then exit;
	inc(spa);dec(src);
	inc(tot2);
	ok2:=judge;
	if ok2 then exit;
	sol_w(tar,src,spa,n-1);
	if ok2 then exit;
	inc(tar);dec(spa);
	inc(tot2);
	ok2:=judge;
        if ok2 then exit;
	sol_w(src,tar,spa,n-1);
        if ok2 then exit;
end;
begin
	//assign(input,'2.in');reset(input);
	//assign(output,'2.out');rewrite(output);
	readln(n,k);
	//n:=18;for k:=131072 to 131072+50 do begin

	tot1:=0;tot2:=0;ok1:=false;ok2:=false;
        a1:=n;b1:=n;a2:=0;b2:=0;a3:=0;b3:=0;
	sol_std(a1,a3,a2,n);
	sol_w(b1,b3,b2,n);
	writeln(tot2);

        //end;
end.
