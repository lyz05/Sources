var
	deep,u,last,n,k:integer;
	total:longint; 
procedure searth(u,last,deep:integer);
var
	i:integer;
begin 
	if (deep=k) then
	begin
		total:=total+1;
		exit; 
	end;
	for i:=last to u div 2 do
		searth(u-i,i,deep+1);
end;
begin 
	read(n,k);
	searth(n,1,1); 
	writeln(total);
end.
