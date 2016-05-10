var	cnt,i,j,k,ans,ans1,ans2,ans3:longint;
procedure work(x,y,z:longint);
begin
	if cnt<10 then begin
		k:=random(2);
		writeln(k);
		case k of
			0:k:=k;
			1:begin
				inc(ans1,x);
				inc(ans2,y);
		  	  	inc(ans3,z);
			  	inc(cnt);
			  end;
		end;
	end;
end;
begin
	//assign(input,'.in');reset(input);
	assign(output,'kenji1.out');rewrite(output);

	//i to 20;
	randomize;
	work(6,75,58);
	work(72,92,89);
	work(37,55,81);
	work(65,22,13);
	work(12,20,40);
	work(5,77,21);
	work(42,43,88);
	work(91,29,79);
	work(21,83,89);
	work(6,16,56);
	work(82,20,18);
	work(19,33,53);
	work(28,62,3);
	work(67,62,50);
	work(48,21,90);
	work(51,3,34);
	work(27,48,22);
	work(42,47,15);
	work(86,51,72);
	work(23,1,80);
	ans:=1;
	ans:=ans*ans1;
	ans:=ans*ans2;
	ans:=ans*ans3;
	close(output);
	//writeln;
	//writeln(ans);
end.
