const   lenn=9999999;
var	t,i,j,k,len,kk,km:longint;	//k is s[i]='X' number
	s,ss:string;		//change
        ans:double;
function work:double;
var	m:longint;
begin
	work:=0;
	while k<>len do begin
		m:=random(len)+1;
		while s[m]='X' do begin
			work:=work+1;
			m:=(m mod len)+1;
		end;
                //if s[m]='X' then begin
                        s[m]:='X';
                        inc(k);
                //end;
	end;
end;
begin
	assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	randomize;
	readln(t);
	for i:=1 to t do begin
		readln(s);
		len:=length(s);
                ss:=s;
                k:=0;
                for j:=1 to len do
		        if s[j]='X' then inc(k);
                km:=k;
                for kk:=1 to lenn do begin
                        s:=ss;
                        k:=km;
		        ans:=ans+work;
                end;
                ans:=ans/lenn;
                writeln(ans:0:6);
	end;
end.
