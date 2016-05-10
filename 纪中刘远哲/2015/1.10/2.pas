const	mo=10000000;
var	i,j,t,len:longint;
	s,ms:ansistring;
        h:array[1..mo] of double;
function hash(s:string;val:double):double;
var	i,h1:longint;
begin
	h1:=0;
	for i:=1 to len do
		if s[i]='X' then h1:=(2*(h1+1)) mod mo
			else h1:=(2*(h1+2)) mod mo;
	if h[h1]<>0 then exit(h[h1]) else begin
		h[h1]:=val;
		exit(0);
	end;
end;
function work(s:string):double;
var	i,j,tot:longint;
begin
	if s=ms then exit(0);
	work:=hash(s,0);
	if work<>0 then exit;
	for i:=1 to len do begin
		if s[i]='.' then begin
			s[i]:='X';
			work:=work+work(s);
			s[i]:='.'
		end else begin
			tot:=0;
			j:=i;
			while s[j]='X' do begin
				inc(tot);
				j:=(j mod len)+1;
			end;
			s[j]:='X';
			work:=work+(work(s)+tot);
			s[j]:='.';
		end;
	end;
	work:=(1/len)*work;
        hash(s,work);
        //writeln(s,' ',work:0:4);
end;
begin
	//assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(t);
	for i:=1 to t do begin
		readln(s);
		ms:='';
		len:=length(s);
		for j:=1 to len do ms:=ms+'X';
		writeln(work(s):0:11);
	end;
end.
