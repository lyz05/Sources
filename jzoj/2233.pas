uses math;
var	i,j,n,m,len,l,r:longint;
	a:array[0..10000] of integer;
        logg:real;
begin
        readln(n);
        len:=0;
        inc(n,2);
        logg:=log2(n);
        if logg=trunc(logg) then len:=-1;
        len:=len+trunc(logg);

        dec(n,2);
        l:=1;r:=1;
        for i:=1 to len do l:=l*2;
	r:=l*2;
	l:=l-1;
        r:=r-2;
       	//writeln(len);
        //writeln(l,' ',r);
        while l<r do begin
           m:=(l-1+r) div 2;
           if n<=m then begin
                write(4);
                r:=m;
           end else begin
                write(7);
                l:=m+1;
           end;
        end;
        writeln;
	

end.
