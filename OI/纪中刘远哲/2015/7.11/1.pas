var	i,j,k,m,n,len:longint;
	s,ans,st,s1:ansistring;		//change
	flag:boolean;
function get(x:longint):string;
var	i:longint;
begin
	get:='';
	for i:=1 to x do get:=get+'*';
end;
begin
	//assign(input,'compress.in');reset(input);
	//assign(output,'compress.out');rewrite(output);

	ans:='';
	readln(s);
	n:=length(s);
	i:=1;
	while i<=n do begin
		len:=2;
		flag:=false;
		while i+2*len-1<=n do begin
			j:=len;
			st:=copy(s,i,len);
			s1:=copy(s,i+j,len);
			while (st=s1) and (i+j<=n) do begin
				flag:=true;
				j:=j+len;
				s1:=copy(s,i+j,len);
			end;
			if flag then begin
				i:=i+j;
				dec(j,len);
				if (ans<>'')and(ans[length(ans)]<>'$') then
					ans:=ans+'$';
				ans:=ans+st;		//zimu
				ans:=ans+get(j div len);//*
				ans:=ans+'$';		//$
				break;
			end;
			inc(len);
		end;
		if not flag then begin
			ans:=ans+s[i];
			inc(i);
		end;
	end;
	if ans[length(ans)]<>'$' then ans:=ans+'$';
	writeln(ans);

	close(input);close(output);
end.
