var	i,j,n,h,len:longint;
	s:ansistring;		//change
	flag:boolean;
function work(x,k,half:longint):boolean;
var	i,l,r:longint;
begin
	//half:=h;
	if odd(x) then begin
		//dec(half);
		l:=k-1;r:=k+1;
	end else begin
		l:=k;r:=k+1
	end;
	for i:=1 to half do begin
		if s[l]<>s[r] then exit(false); 
		dec(l);inc(r);
	end;
	exit(true);
end;
begin
	assign(input,'necklace.in');reset(input);
	assign(output,'necklace.out');rewrite(output);
	
	readln(n);
	for i:=1 to n do begin
		flag:=false;
		readln(s);
		len:=length(s);
		
		if odd(len) then begin
			s:=s+s;
			h:=len>>1+1;
			for j:=1 to len do 
				if work(1,h+j-1,h-1) then begin
					flag:=true;
					break;
				end;
		end else begin
			s:=s+s;
			h:=len>>1;
			for j:=1 to len do begin 
				if work(2,h+j-1,h) or work(1,h+j,h) then
			       	begin
					flag:=true;
					break;
				end;
			 
			end;
		end;
		if flag then writeln('YES') else writeln('NO');
	end;

	close(input);close(output);
end.
