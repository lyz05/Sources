var	b:array[0..100]of boolean;
	n,i,a:longint;
	f,m,j,s,k:qword;
function js(x:longint):qword;
var	c:longint;
	ss:qword;
begin
	ss:=1;
	for c:=1 to x do ss:=ss*c;
	exit(ss);
end;
begin
	readln(n,m);
	fillchar(b,sizeof(b),true);
	for i:=n downto 1 do begin
       		f:=js(i-1);
       		j:=m div f;
		s:=0;
		if m<>j*f then k:=j+1 else k:=j;
       		if k=0 then k:=i;
	       	for a:=1 to n do 
			if b[a] then begin
		       		inc(s); 
				if s=k then begin
			       		write(a); 
					if i<>1 then write(' '); 
					b[a]:=false; 
					break;
				end; 
			end;
       		m:=m-j*f; 
	end;
	writeln;
end.
