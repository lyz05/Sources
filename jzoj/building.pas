var n,i,j:longint;
    ans,max:int64;
    p1,p2:boolean;
    a:array[0..1000001] of longint;
begin
	//assign(input,'building.in');reset(input);
	//assign(output,'building.out');rewrite(output);
	readln(n);
	p1:=true;
	p2:=true;
	for i:=1 to n-1 do begin
		readln(a[i]);
		if a[i]>max+1 then begin
                        if a[i]=max+2 then begin
			        if not p1 then p2:=false
			        else p1:=false;
                        end else p2:=false;
		end;
		if max<a[i] then max:=a[i];
		ans:=ans+max;
	end;
	if (not p1)and(p2) then begin
		writeln(1);
		close(input);close(output);
		halt;
	end;
	if not p2 then begin
		writeln(0);
		close(input);close(output);
		halt;
	end;
	writeln(ans+1);
	close(input);close(output);
end.
