var	i,j,k,kk,m,n,h,tot,ans,len:longint;
	s:string;
begin
	assign(input,'string.in');reset(input);
	//assign(output,'string.out');rewrite(output);

	readln(s);
	readln(kk);
	len:=length(s);
	for i:=1 to len do
		for j:=i to len do begin
			tot:=0;
			h:=(j-i+1+1) div 2;
			for k:=0 to h-1 do begin
				if s[i+k]<>s[j-k] then inc(tot);
			end;	
			if tot<=kk then 
				inc(ans);
		end;
	writeln(ans);

	//close(input);close(output);
end.
