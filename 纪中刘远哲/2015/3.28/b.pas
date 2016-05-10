var	s:ansistring;			//change
	i:integer;
function judge(var s:ansistring):boolean;	//change
var	i,j,len:longint;
begin
	len:=length(s);
	for i:=1 to len div 2 do begin	
		for j:=1 to len-i*2+1 do begin
			if copy(s,j,i)=copy(s,j+i,i) then begin
				delete(s,j,i);
				exit(true);
			end;
		end;	
	end;
	exit(false);

end;
begin
	assign(input,'b.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(s);
	while judge(s) do i:=i xor 1;
	writeln(s);
end.
