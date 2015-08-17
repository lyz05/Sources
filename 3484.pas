var	i,j,k,last,len1,len2:longint;
	ans:int64;
	s1,s2:ansistring;
begin
	readln(s1);len1:=length(s1);
	readln(s2);len2:=length(s2);
	last:=0;ans:=0;
	for i:=1 to len1-len2+1 do begin
		if s1[i]=s2[1] then begin
			k:=2;
			for j:=i+1 to len1 do begin
				if s1[j]=s2[k] then begin
					inc(k);
					if k>len2 then begin
						inc(ans,(i-last)*(len1-j+1));
						break;
					end;
				end;
			end;
			last:=i;
		end;
	end;
	writeln(ans);
end.
