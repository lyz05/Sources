var	n,l,r,mid,ans:longint;
	s:string;		//change
function judge(len:longint):boolean;
var	flag:boolean;
	i,j,k,m:longint;
begin
	for i:=1 to n-len+1 do begin
		j:=i+len-1;
		flag:=true;
		for k:=i to j do begin
			m:=len-(k-i)+i-1;
			if s[k]<>s[m] then begin
				flag:=false;
				break;
			end;
			if k=m then break;
		end;
		if flag then exit(flag);
	end;
	exit(false);
end;
begin
	assign(input,'string.in');reset(input);
	//assign(output,'string.out');rewrite(output);

	readln(s);
	l:=1;r:=length(s);
	n:=r;
	//for i:=l to r do s1:=s[i]+s1;
	while (l<r) do begin
		mid:=(l+r) >> 1;
		if judge(mid) then begin
			ans:=mid;
			l:=mid+1;
		end else r:=mid-1;
	end;
	writeln(ans);

	//close(input);close(output);
end.
