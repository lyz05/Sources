var	i,j,t,len:longint;
	s,ms:string;
function work(s:string):double;
var	i,j,tot:longint;
begin
	if s=ms then exit(0);
	work:=0;
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
