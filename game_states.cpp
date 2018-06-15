#include "game_states.h"
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

SDL_Surface* wLevel;
SDL_Surface* wName;
SDL_Surface* wScore;
SDL_Surface* wwName;
SDL_Surface *L1; SDL_Surface *N1; SDL_Surface *S1; SDL_Surface *n1;

class Rank{
  string user_name;
  int level;
  int score;
public:
  Rank(string user_name, int level, int score){
    this->user_name=user_name;
    this->level=level;
    this->score=score;
  }
  string getName(){
    return user_name;
  }
  int getLevel(){
    return level;
  }
  int getScore(){
    return score;
  }
};

bool compare(Rank a, Rank b){
  return a.getScore() > b.getScore();
}

vector<Rank> rankingList;

Mix_Music *START;
Mix_Music *GameOver;
Mix_Music *PLAY;
Mix_Music *TEST;
Mix_Chunk *bomb;
Mix_Chunk *drop;
Mix_Chunk *clean;
SDL_Surface* Life;

void menu()
{
	int mode = INITIAL_MODE;
	int level = 0;

	while (mode != EXIT)
	{
		switch (mode)
		{
		case INITIAL_MODE:
			mode = select_mode();
			break;
		case SINGLE_MODE:
			init();
			main_game(1, SINGLE_MODE);
			mode = select_level();
			break;
		case MULTI_MODE:
			mode = socketing();
			break;
		default:
			break;
		}
	}
}

int show_rank(int num){
  int quit = 0;
  int n = num;
  string tempN;
  string tempL;
  string tempS;
  char* tName;
  char* tLevel;
  char* tScore;

	while (quit == 0)
	{
		if (SDL_PollEvent(&event))
		{
      message = TTF_RenderText_Solid(font, "Ranking", white);
			apply_surface(0, 0, background, screen);

			SDL_Flip(screen);

      apply_surface((640 - message->w) / 2, 5, message, screen);

      wName = TTF_RenderText_Solid(font, "Name", white);
      wScore = TTF_RenderText_Solid(font, "Score", white);
      wLevel = TTF_RenderText_Solid(font, "Level", white);

      apply_surface(150, 480/13*2, wName, screen);
      apply_surface(400, 480/13*2, wScore, screen);
      apply_surface(550, 480/13*2, wLevel, screen);
      SDL_Flip(screen);

      if (n > 10) n = 10;

      for(int i=1; i<=n; i++){
        string s = to_string(i);
        char const *pchar = s.c_str();
        n1 = TTF_RenderText_Solid(font, pchar, white);

        tempN = rankingList[i-1].getName();
        tempS = to_string(rankingList[i-1].getScore());
        tempL = to_string(rankingList[i-1].getLevel());

        char const *ttN = tempN.c_str();
        char const *ttS = tempS.c_str();
        char const *ttL = tempL.c_str();

        N1 = TTF_RenderText_Solid(font, ttN, white);
        S1 = TTF_RenderText_Solid(font, ttS, white);
        L1 = TTF_RenderText_Solid(font, ttL, white);

        apply_surface( 50, 480/13*(i+2), n1, screen);
        apply_surface( 150, 480/13*(i+2), N1, screen);
        apply_surface( 400, 480/13*(i+2), S1, screen);
        apply_surface( 550, 480/13*(i+2), L1, screen);
      }

      SDL_Flip(screen);

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_SPACE:
				{
					message = NULL;
          return 0;
					break;
				}
				case SDLK_ESCAPE://esc 키가 눌리면 종료
        return 0;
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_QUIT)
			{
        return 0;
				quit = 1;
			}
		}
	}
  return 0;
}

string write_name(string name){
  int quit = 0;
	int mode = 0;
  char* tempName;
  name="";
	while (quit == 0)
	{
		if (SDL_PollEvent(&event))
		{
      message = TTF_RenderText_Solid(font, "Write your name and press space", white);
			apply_surface(0, 0, background, screen);
			SDL_Flip(screen);
			title_message = TTF_RenderText_Solid(font2, "Active Dodge", white);
			apply_surface((640 - title_message->w) / 2, 80, title_message, screen);
			apply_surface((640 - message->w) / 2, 480 / 2 - message->h, message, screen);
			SDL_Flip(screen);
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
          case SDLK_0:
          {
            name+="0";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_1:
          {
            name+="1";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_2:
          {
            name+="2";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_3:
          {
            name+="3";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_4:
          {
            name+="4";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_5:
          {
            name+="5";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_6:
          {
            name+="6";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_7:
          {
            name+="7";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_8:
          {
            name+="8";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_9:
          {
            name+="9";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_a:
          {
            name+="a";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_b:
          {
            name+="b";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_c:
          {
            name+="c";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_d:
          {
            name+="d";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_e:
          {
            name+="e";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_f:
          {
            name+="f";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_g:
          {
            name+="g";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_h:
          {
            name+="h";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_i:
          {
            name+="i";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_j:
          {
            name+="j";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_k:
          {
            name+="k";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_l:
          {
            name+="l";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_m:
          {
            name+="m";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_n:
          {
            name+="n";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_o:
          {
            name+="o";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_p:
          {
            name+="p";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_q:
          {
            name+="q";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_r:
          {
            name+="r";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_s:
          {
            name+="s";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_t:
          {
            name+="t";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_u:
          {
            name+="u";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_v:
          {
            name+="v";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_w:
          {
            name+="w";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_x:
          {
            name+="x";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_y:
          {
            name+="y";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
          case SDLK_z:
          {
            name+="z";
            tempName = new char[name.size()+1];
            copy(name.begin(), name.end(), tempName);
            wwName= TTF_RenderText_Solid(font, tempName, white);
            apply_surface(200, 480/2 + 50, wwName, screen);
      			SDL_Flip(screen);
            break;
          }
				case SDLK_SPACE:
				{
					message = NULL;
					return name;
					break;
				}
				case SDLK_ESCAPE://esc 키가 눌리면 종료
					return name;
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_QUIT)
			{
				return name;
				quit = 1;
			}
		}
	}
  return name;
}

void ranking(int level, int score, int state){
string t_name;
string name;
name = write_name(t_name);//플레이어의 닉네임 넣는 창

if (name==""){
  name="guest";//이름 입력 안 할 경우 guest로 자동 지정
}
	Rank temp(name, level, score);
  rankingList.push_back(temp);//이번에 플레이한 정보 넣는다

  string p_name;
	int p_level;
	int p_score;
	int num;//몇 명의 정보를 불러와야 하는지

	std::ifstream rank_in;
	rank_in.open("rank.txt");
	rank_in>>num;//몇 명인지 불러온다

  if(num!=0){
	for(int i=0; i<num; i++){//저장되어 있는 수 동안
		rank_in>>p_name;
		rank_in>>p_level;
		rank_in>>p_score;
		Rank r(p_name, p_level, p_score);
		rankingList.push_back(r);
	}
}
	rank_in.close();
	num++;

  sort(rankingList.begin(), rankingList.end(), compare);

  int fflag = show_rank(num);//랭킹 출력. 랭킹의 총 개수 전달

	std::ofstream rank_save;
	rank_save.open("rank.txt");
	rank_save<<num<<endl;
	for(int i=0;i<num;i++){
		rank_save<<rankingList[i].getName()<<endl;
		rank_save<<rankingList[i].getLevel()<<endl;
		rank_save<<rankingList[i].getScore()<<endl;
	}
	rank_save.close();

	game_over(level, score, SINGLE_MODE);
}

bool load_files()
{
	background = load_image("assets/background.png");
	dollar = load_image("assets/bonus.png");
	font = TTF_OpenFont("assets/210 Macaron B.ttf", 24);
	font2 = TTF_OpenFont("assets/210 Haneuljungwon B.ttf", 72);
  health = load_image("assets/health.png");
  pil = load_image("assets/pil.png");

	player = SDL_LoadBMP("assets/player1.bmp");
	player2 = SDL_LoadBMP("assets/player2.bmp");
	ball = load_image("assets/rocket.bmp");
	heart = SDL_LoadBMP("assets/heart.bmp");
  Life = load_image("assets/life.png");
	enemy_heart = SDL_LoadBMP("assets/enemy_heart.bmp");

  if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048)<0) {
    return false;
  }

  START = Mix_LoadMUS("assets/start.wav");
  GameOver = Mix_LoadMUS("assets/game over.wav");
  PLAY = Mix_LoadMUS("assets/play.wav");
  TEST = Mix_LoadMUS("assets/test.wav");
  drop = Mix_LoadWAV("assets/test.wav");
  bomb = Mix_LoadWAV("assets/bomb.wav");
  clean = Mix_LoadWAV("assets/clear.wav");

	if (background == NULL)
	{
		return false;
	}

	if (font == NULL)
	{
		return false;
	}

	return true;
}

int select_mode()
{
  Mix_PlayMusic(START,3);
	bool quit = false;
	int mode = 0;
	while (quit == false)
	{
		if (SDL_PollEvent(&event))
		{
			message = TTF_RenderText_Solid(font, "Press space to start, esc key to quit", white);
			apply_surface(0, 0, background, screen);
			title_message = TTF_RenderText_Solid(font2, "Active Dodge", white);
			apply_surface((640 - title_message->w) / 2, 80, title_message, screen);
			apply_surface((640 - message->w) / 2, 480 / 2 - message->h, message, screen);
			message = TTF_RenderText_Solid(font, "Single         Multi", white);
			apply_surface((640 - message->w) / 2, 480 / 2 + message->h, message, screen);
			message2 = TTF_RenderText_Solid(font, "Single         ", white);
			int tmp = message2->w;
			message2 = TTF_RenderText_Solid(font, ">", white);
			apply_surface((640 - message->w) / 2 - 8 + mode * tmp, 480 / 2 + message->h, message2, screen);
			SDL_Flip(screen);
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_RIGHT:
				{
					if (mode >= 1) break;
					mode++;
					break;
				}
				case SDLK_LEFT:
				{
					if (mode <= 0) break;
					mode--;
					break;
				}
				case SDLK_SPACE:
				{
					message = NULL;
					if (mode == 1) return MULTI_MODE;
					else if (mode == 0) return SINGLE_MODE;
					break;
				}
				case SDLK_ESCAPE://esc 키가 눌리면 종료
					return EXIT;
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_QUIT)
			{
				return EXIT;
				quit = true;
			}
		}
	}
}

int select_level()
{
	bool quit = false;
	int selector = 0;
	while (quit == false)
	{
		if (SDL_PollEvent(&event))
		{
			message = TTF_RenderText_Solid(font, "Press space to start, esc key to quit", white);
			apply_surface(0, 0, background, screen);
			title_message = TTF_RenderText_Solid(font2, "Active Dodge", white);
			apply_surface((640 - title_message->w) / 2, 100, title_message, screen);
			apply_surface((640 - message->w) / 2, 480 / 2 - message->h, message, screen);
			//message = TTF_RenderText_Solid(font, "level 1         level 2        level 3", textColor);
			//apply_surface((640 - message->w) / 2, 480 / 2 + message->h, message, screen);
			//message2 = TTF_RenderText_Solid(font, "level 1         ", textColor);
			//int tmp = message2->w;
			//message2 = TTF_RenderText_Solid(font, ">", textColor);
			//apply_surface((640 - message->w) / 2 - 8 + selector * tmp, 480 / 2 + message->h, message2, screen);
			SDL_Flip(screen);

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				/*
				case SDLK_RIGHT:
				{
					if (selector >= 2) break;
					selector++;
					break;
				}
				case SDLK_LEFT:
				{
					if (selector <= 0) break;
					selector--;
					break;
				}
				*/
				case SDLK_SPACE:
				{
					message = NULL;
					init();
					main_game(selector, SINGLE_MODE);
					return INITIAL_MODE;
					break;
				}
				case SDLK_ESCAPE://esc 키가 눌리면 종료
					return INITIAL_MODE;
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_QUIT)
			{
				return EXIT;
				quit = true;
			}
		}
	}
}

int socketing()
{
	client = socket(AF_INET, SOCK_STREAM, 0);
	int yes = 1;
	if(setsockopt(client, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) std::cout << "socket setting error" << std::endl;

	if (client < 0)
	{
		std::cout << "\n소켓 준비 에러..." << std::endl;
	}

	std::cout << "\n=> 소켓 생성 완료..." << std::endl;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portNum);

	bool isServer = true;
	int count = 0;
	inet_pton(AF_INET, ip, &server_addr.sin_addr);

	bool isConnect = false;
	bool* cntPointer = &isConnect;
	std::thread waitingMassage(waiting, &cntPointer);
	while (true)
	{
		if (connect(client, (struct sockaddr *)&server_addr, sizeof(server_addr)) != -1)
		{
			isServer = false;
			isConnect = true;
			waitingMassage.join();
		}
		count++;
		if (count == 3) break;
	}

	if (isServer)
	{
		inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr); // 초기값인 0.0.0.0으로 초기화

		while ((bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0)
		{
			//std::cout << "=> Error binding connection, the socket has already been established..." << std::endl;
			//count = (count + 1) % 4;

			//std::string str = "Server is Creating, Esc key to quit";
			//message = TTF_RenderText_Solid(font, str.c_str(), textColor);
			//apply_surface(0, 0, background, screen);
			//apply_surface((640 - message->w) / 2, 480 / 2 - message->h, message, screen);
			//SDL_Delay(500);
			//std::string str2 = "Waiting";
			//for (int j = 0; j < count; j++) str2 += " .";
			//message2 = TTF_RenderText_Solid(font, str2.c_str(), textColor);
			//apply_surface((640 - message2->w) / 2, 480 / 2 - message2->h + message->h + 10, message2, screen);
			SDL_Flip(screen);
			if (SDL_PollEvent(&event))
			{
				std::string str = "Server is Creating, Esc key to quit";
				message = TTF_RenderText_Solid(font, str.c_str(), white);
				apply_surface(0, 0, background, screen);
				apply_surface((640 - message->w) / 2, 480 / 2 - message->h, message, screen);

				if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE://esc 키가 눌리면 종료
						return INITIAL_MODE;
						break;
					default:
						break;
					}
				}
				else if (event.type == SDL_QUIT)
				{
					return EXIT;
				}
			}
		}
		server_addr.sin_addr.s_addr = htons(INADDR_ANY);

		size = sizeof(server_addr);
		std::cout << "=> Looking for clients..." << std::endl;
		server = -1;

		listen(client, 1);

		std::thread listenFor(waitClient, &cntPointer);

		while (!isConnect)
		{
			if (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE://esc 키가 눌리면 종료
						isConnect = true;
						int tmp_client;
						tmp_client = socket(AF_INET, SOCK_STREAM, 0);
						inet_pton(AF_INET, ip, &server_addr.sin_addr);
						if (connect(tmp_client, (struct sockaddr*)&server_addr, size) == -1)
						{
							//error message
							std::cout << "Connecting Error!\nServer was not created." << std::endl;
							exit(1);
						}

						//3번 반복
						//int count = 0;
						/*while (true)
						{
						if (connect(tmp_client, (struct sockaddr *)&server_addr, sizeof(server_addr)) != -1)
						std::cout << "success" << std::endl;
						else std::cout << "fail" << std::endl;
						count++;
						if (count == 3) break;
						}*/
						close(tmp_client);
						close(client);
						close(server);
						listenFor.join();
						waitingMassage.join();
						return INITIAL_MODE;
						break;
					default:
						break;
					}
				}
				else if (event.type == SDL_QUIT)
				{
					return EXIT;
				}
			}
		}
		listenFor.join();
		waitingMassage.join();

		/*count = -1;
		while (true)
		{
			server = accept(client, (struct sockaddr *)&server_addr, &size);
			if(server >= 0) break;
			count = (count + 1) % 4;
			if (waiting(count) == INITIAL_MODE) return INITIAL_MODE;
		}*/
		/* ------------- ACCEPTING CLIENTS  ------------- */
		/* ----------------- listen() ------------------- */

		// first check if it is valid or not
		/*
		if (server < 0)
			std::cout << "=> Error on accepting..." << std::endl;
		*/

		buffer_int[0] = (unsigned int)time(NULL);
		send(server, buffer_int, bufsize, 0);
		srand(buffer_int[0]);
		message = NULL;
		init();
		main_game(0, SERVER_MODE);
		listenFor.~thread();
	}
	else
	{
		inet_pton(AF_INET, ip, &server_addr.sin_addr);
		/*
		while (connect(client, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0)
		{}
		*/
		std::cout << "연결 완료!" << std::endl;
		std::cout << "=> 연결된 서버 포트 번호: " << portNum << std::endl;
		int iResult;
		struct timeval tv;
		bool timeout = false;
		fd_set rfds;
		FD_ZERO(&rfds);
		FD_SET(client, &rfds);

		tv.tv_sec = 5;
		tv.tv_usec = 0;

		iResult = select(client + 1, &rfds, (fd_set *)0, (fd_set *)0, &tv);
		if (iResult > 0)
		{
			recv(client, buffer_int, bufsize, 0);
			timeout = true;
		}
		if (!timeout) return INITIAL_MODE;

		srand(buffer_int[0]);
		message = NULL;
		init();
		main_game(0, CLIENT_MODE);
	}

	return INITIAL_MODE;
}

void waiting(bool **isConnect)
{
	int count = 0;
	while (!(**isConnect))
	{
		std::string str = "Waiting";
		for (int j = 0; j < count; j++) str += " .";
		message = TTF_RenderText_Solid(font, str.c_str(), white);
		apply_surface(0, 0, background, screen);
		apply_surface((640 - message->w) / 2, 480 / 2 - message->h, message, screen);
		SDL_Flip(screen);
		SDL_Delay(500);
		count = (count + 1) % 4;
	}
}

void waitClient(bool **isConnect)
{
	 server = accept(client, (struct sockaddr *)&server_addr, &size);
	 **isConnect = true;
}

bool init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

	if (screen == NULL)
	{
		return false;
	}

	if (TTF_Init() == -1)
	{
		return false;
	}
	srand(time(NULL));
	SDL_WM_SetCaption("Active", NULL);

	return true;
}

void clean_up()
{
	SDL_FreeSurface(background);
	SDL_FreeSurface(message);
	SDL_FreeSurface(screen);
	SDL_FreeSurface(ball);
  SDL_FreeSurface(health);
	SDL_FreeSurface(dollar);
  SDL_FreeSurface(pil);

  Mix_FreeMusic(START);
  Mix_FreeMusic(GameOver);
  Mix_FreeMusic(TEST);
  Mix_FreeMusic(PLAY);
	TTF_CloseFont(font);
	TTF_Quit();

	SDL_Quit();
}

void main_game(int selector, int mode)//난이도 선택 변수
{
  Mix_PlayMusic(PLAY,-1);
	using namespace std;
	bool quit = false;
	//client side player
	int player_position = SCREEN_WIDTH / 2;
	int player_position_y = SCREEN_HEIGHT - 3;
	//server side player
	int player2_position = SCREEN_WIDTH / 2;
	int player2_position_y = SCREEN_HEIGHT - 3;
	Uint8 *keystates = NULL;
	int start_time = SDL_GetTicks();
	int level = 1 + selector; // level 정의
	int life = 3; // life 추가
	int enemy_life = 3;
	int current_balls = 0;
	int current_addlife = 0;
	int current_addscore = 0;
  int current_clear = 0;
  int scorecheck = 0; //addlife위함

	int i = 0;
	int Die_Count = 0;

	int fps_timer = 0;
	int delay = 0;
	int frames = 0;
	int fps_calc_timer = SDL_GetTicks();
	int score = 0;

	//time check, score
	clock_t tstart = clock();
	clock_t tend;
	long ttemp;
	long sec=0; //seconds

	int randomball[MAX_BALLS]; // 떨어지는 볼의 속도를 랜덤하게 조정하기 위해 선언한 배열
	int randomadddlife[MAX_ADDLIFE];
	int randomaddscore[MAX_ADDSCORE];
  int randomclear[MAX_CLEAR];

	if (mode == SINGLE_MODE) srand((unsigned int)time(NULL)); //in Single Mode set random ball

	for (i = 0; i < MAX_BALLS; i++)
		randomball[i] = 0;
	for (i = 0; i < MAX_ADDLIFE; i++)
		randomadddlife[i] = 0;
	for (i = 0; i < MAX_ADDSCORE; i++)
		randomaddscore[i] = 0;
  for (i = 0; i < MAX_CLEAR; i++)
  	randomclear[i] = 0;

	init_ball();
	init_addlife();
	init_addscore();
  init_clear();

	while (quit == false)
	{
		for (i = 0; i < current_balls; i++)
		{
			randomball[i] = (double)rand() / RAND_MAX * (level - 1) + BALL_VELOCITY; // 초기 속도와 레벨 사이의 난수 생성
		}
		for (i = 0; i < current_addlife; i++)
		{
			randomadddlife[i] = (double)rand() / RAND_MAX * (level - 1) + ADDLIFE_VELOCITY;
		}
		for (i = 0; i < current_addscore; i++)
		{
			randomaddscore[i] = (double)rand() / RAND_MAX * (level - 1) + ADDSCORE_VELOCITY;
		}
    for (i = 0; i < current_clear; i++)
		{
			randomclear[i] = (double)rand() / RAND_MAX * (level - 1) + CLEAR_VELOCITY;
		}


		fps_timer = SDL_GetTicks();
		if (SDL_GetTicks() - start_time > 1)
		{
			start_time = SDL_GetTicks();
			for (i = 0; i < current_balls; i++)
			{
				balls[i].y += randomball[i];//level증가를 위해서 기존 값에 level을 곱해줌
			}
			for (i = 0; i < current_addlife; i++)
			{
				addlife[i].y += randomadddlife[i];
			}
			for (i = 0; i < current_addscore; i++)
			{
				addscore[i].y += randomaddscore[i];
			}
      for (i = 0; i < current_clear; i++)
			{
				clear[i].y += randomclear[i];
			}
		}
		if (current_balls < MAX_BALLS)
		{
			for (i = 0; i < MAX_BALLS; i++)
			{
				if (balls[i].y > SCREEN_HEIGHT || balls[i].y == 0)
				{
					SDL_Rect new_ball;
					new_ball.x = BALL_SIZE / 2 + rand() % (SCREEN_WIDTH - BALL_SIZE / 2);
					new_ball.y = -(5 + rand() % 350);
					new_ball.w = new_ball.h = BALL_SIZE;
					balls[i] = new_ball;
				}
			}
			current_balls = MAX_BALLS;
		}
		if (current_addlife < MAX_ADDLIFE)
		{
			for (i = 0; i < MAX_ADDLIFE; i++)
			{
				if (addlife[i].y > SCREEN_HEIGHT)
				{
					SDL_Rect new_addlife;
					new_addlife.x = ADDLIFE_SIZE / 2 + rand() % (SCREEN_WIDTH - ADDLIFE_SIZE / 2);
					new_addlife.y = -(5 + rand() % 350);
					new_addlife.w = new_addlife.h = ADDLIFE_SIZE;
					addlife[i] = new_addlife;

				}
			}
			current_addlife = MAX_ADDLIFE;
		}
		if (current_addscore < MAX_ADDSCORE)
		{
			for (i = 0; i < MAX_ADDSCORE; i++)
			{
				if (addscore[i].y > SCREEN_HEIGHT || addscore[i].y == 0)
				{
					SDL_Rect new_addscore;
					new_addscore.x = ADDSCORE_SIZE / 2 + rand() % (SCREEN_WIDTH - ADDSCORE_SIZE / 2);
					new_addscore.y = -(5 + rand() % 350);
					new_addscore.w = new_addscore.h = ADDSCORE_SIZE;
					addscore[i] = new_addscore;

				}
			}
			current_addscore = MAX_ADDSCORE;
		}
    if (current_clear < MAX_CLEAR)
		{
			for (i = 0; i < MAX_CLEAR; i++)
			{
				if (clear[i].y > SCREEN_HEIGHT || clear[i].y == 0)
				{
					SDL_Rect new_clear;
					new_clear.x = CLEAR_SIZE / 2 + rand() % (SCREEN_WIDTH - CLEAR_SIZE / 2);
					new_clear.y = -(5 + rand() % 350);
					new_clear.w = new_clear.h = CLEAR_SIZE;
					clear[i] = new_clear;

				}
			}
			current_clear = MAX_CLEAR;
		}

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				balls[0].x = player_position;
				balls[0].y = player_position_y;
				life = 1;
				Die_Count = 0;
			}
		}

		keystates = SDL_GetKeyState(NULL);

		if (keystates[SDLK_ESCAPE])
		{
			balls[0].x = player_position;
			balls[0].y = player_position_y;
			life = 1;
			Die_Count = 0;
		}

		if (keystates[SDLK_LEFT] && player_position > PLAYER_WIDTH / 2)
		{
			player_position--;
		}

		if (keystates[SDLK_RIGHT] && player_position < SCREEN_WIDTH - PLAYER_WIDTH / 2)
		{
			player_position++;
		}

		if (keystates[SDLK_UP] && player_position_y > PLAYER_HEIGHT / 2)
		{
			player_position_y--;
		}

		if (keystates[SDLK_DOWN] && player_position_y < SCREEN_HEIGHT - PLAYER_HEIGHT / 2)
		{
			player_position_y++;
		}//위 아래 이동 추가

		apply_surface(0, 0, background, screen);
		if (life == 5) {
			apply_surface(420, 20, heart, screen); apply_surface(460, 20, heart, screen); apply_surface(500, 20, heart, screen); apply_surface(540, 20, heart, screen); apply_surface(580, 20, heart, screen);
		}
		if (life == 4) {
			apply_surface(460, 20, heart, screen); apply_surface(500, 20, heart, screen); apply_surface(540, 20, heart, screen); apply_surface(580, 20, heart, screen);
		}
		if (life == 3) {
			apply_surface(500, 20, heart, screen); apply_surface(540, 20, heart, screen); apply_surface(580, 20, heart, screen);
		}
		// heart decrease as life goes down
		else if (life == 2) {
			apply_surface(540, 20, heart, screen); apply_surface(580, 20, heart, screen);
		}
		else if (life == 1) {
			apply_surface(580, 20, heart, screen);
		}

    for (i=0; i < MAX_ADDLIFE; i++)
    {
      apply_surface(addlife[i].x, addlife[i].y, Life, screen);
      if (score % 50 == 0)
      {
        current_addlife--;
      }
    }
    for (i=0; i < MAX_ADDSCORE; i++)
    {
      apply_surface(addscore[i].x, addscore[i].y, dollar, screen);
      if (score % 40 == 0)
      {
        current_addscore--;
      }
    }
    for (i=0; i < MAX_CLEAR; i++)
    {
      apply_surface(clear[i].x, clear[i].y, pil, screen);
      if (score % 40 == 0)
      {
        current_clear--;
      }
    }

  	for (i = 0; i < MAX_BALLS; i++)
		{
    	// printf("ball %i: %i %i\n",i , balls[i].x, balls[i].y);
			apply_surface(balls[i].x, balls[i].y, ball, screen);//판정을 위해서 고친 부분
      if (balls[i].y > SCREEN_HEIGHT)
			{
				current_balls--;
				score++;

				if (score > LEVEL_UP_COUNT * (level - selector))
				{
					level++;//score의 상태에 따라 레벨 증가
		 		}
			}

			SDL_Rect player_rect;
			SDL_Rect player_rect2;
			player_rect.x = player_position - PLAYER_WIDTH / 2;
			player_rect.y = player_position_y - PLAYER_HEIGHT / 2;
			player_rect.w = PLAYER_WIDTH;
			player_rect.h = PLAYER_HEIGHT;
			player_rect2.x = player2_position - PLAYER_WIDTH / 2;
			player_rect2.y = player2_position_y - PLAYER_HEIGHT / 2;
			player_rect2.w = PLAYER_WIDTH;
			player_rect2.h = PLAYER_HEIGHT;

      if (intersects(addlife[i], player_rect))
      {
        Mix_PlayChannel(-1, drop, 0);
        life++;
        addlife[i].x=-100;

      }
      if (intersects(addscore[i], player_rect))
      {
        Mix_PlayChannel(-1, drop, 0);
        score+=5;
        addscore[i].x=-100;
      }
      if (intersects(clear[i], player_rect))
      {
        Mix_PlayChannel(-1, clean, 0);
        init_ball();
        init_addlife();
        init_addscore();
        clear[i].x=-100;
      }

      if (intersects(balls[i], player_rect) && Die_Count == 0)
			{
        Mix_PlayChannel(-1, bomb, 0);
				life--;
				if (life <= 0) //life소진시 종료
				{
					if (enemy_life != 0)
						switch (mode)
						{
							//server side
						case SERVER_MODE:
							std::cout << "SERVER SIDE :";
							std::cout << "Last Client: ";
							recv(server, buffer_int, bufsize, 0);
							player2_position = buffer_int[0];
							player2_position_y = buffer_int[1];
							enemy_life = buffer_int[2];
							std::cout << buffer_int[0] << " " << buffer_int[1] << " " << buffer_int[2] << std::endl;
							buffer_int[0] = player_position;
							buffer_int[1] = player_position_y;
							buffer_int[2] = life;
							std::cout << "Last Server: ";
							std::cout << buffer_int[0] << " " << buffer_int[1] << " " << buffer_int[2] << std::endl;
							send(server, buffer_int, bufsize, 0);
							break;
							//client side
						case CLIENT_MODE:
							std::cout << "CLIENT SIDE :";
							std::cout << "Last Client: ";
							buffer_int[0] = player_position;
							buffer_int[1] = player_position_y;
							buffer_int[2] = life;
							std::cout << buffer_int[0] << " " << buffer_int[1] << " " << buffer_int[2] << std::endl;
							send(client, buffer_int, bufsize, 0);
							std::cout << "Last Server: ";
							recv(client, buffer_int, bufsize, 0);
							player2_position = buffer_int[0];
							player2_position_y = buffer_int[1];
							enemy_life = buffer_int[2];
							std::cout << buffer_int[0] << " " << buffer_int[1] << " " << buffer_int[2] << std::endl;
							break;
						default:
							break;
						}
						close(server);
						close(client);

					if(mode == SINGLE_MODE)
					{
						ranking(level, score, SINGLE_MODE);
						//game_over(level, score, SINGLE_MODE);
					}
					else
					{
						game_over(level, score, LOSER);// 2 == LOSE_CASE
					}
					quit = true;
				}
				else //life가 남아있으면 공 초기화후 계속
				{
					Die_Count++;
				}
			}
		}

  	if (Die_Count == 0 || Die_Count % 2 == 0)
		{
			if (Die_Count >= 600) Die_Count = 0;
			apply_surface(player_position - PLAYER_WIDTH / 2, player_position_y - PLAYER_HEIGHT / 2/*SCREEN_HEIGHT - PLAYER_HEIGHT*/, player, screen);//player표시를 이동에 따라 표시
			SDL_SetColorKey(player, SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 255, 255, 255));
		}
		if (Die_Count > 0) Die_Count++;

		if ((mode == CLIENT_MODE || mode == SERVER_MODE) && enemy_life > 0)//Socket 일때 만 표시
		{
			apply_surface(player2_position - PLAYER_WIDTH / 2, player2_position_y - PLAYER_HEIGHT / 2/*SCREEN_HEIGHT - PLAYER_HEIGHT*/, player2, screen);//player2표시를 이동에 따라 표시
			SDL_SetColorKey(player2, SDL_SRCCOLORKEY, SDL_MapRGB(player2->format, 255, 255, 255));
			// Present enemy_life on screen
			if (enemy_life == 5) {
			apply_surface(420, 60, enemy_heart, screen); apply_surface(460, 60, enemy_heart, screen); apply_surface(500, 60, enemy_heart, screen); apply_surface(540, 60, enemy_heart, screen); apply_surface(580, 60, enemy_heart, screen);
			}
			if (enemy_life == 4) {
			apply_surface(460, 60, enemy_heart, screen); apply_surface(500, 60, enemy_heart, screen); apply_surface(540, 60, enemy_heart, screen); apply_surface(580, 60, enemy_heart, screen);
			}
			if (enemy_life == 3) {
			apply_surface(500, 60, enemy_heart, screen); apply_surface(540, 60, enemy_heart, screen); apply_surface(580, 60, enemy_heart, screen);
			}
			else if (enemy_life == 2) {
			apply_surface(540, 60, enemy_heart, screen); apply_surface(580, 60, enemy_heart, screen);
			}
			else if (enemy_life == 1) {
			apply_surface(580, 60, enemy_heart, screen);
			}

		}

		std::stringstream caption, caption2;
		caption << /* "FPS: " << (int)(frames*1000.0/(SDL_GetTicks() - fps_calc_timer+1)) << */"Score: " << score
			<< "       Level: " << level;//level 추가로 표시
		message = TTF_RenderText_Solid(font, caption.str().c_str(), white);
		caption2 << "Life: " << life;
		message2 = TTF_RenderText_Solid(font, caption2.str().c_str(), white);
		if (SDL_GetTicks() - fps_calc_timer > 5000)
		{
			frames = 1;
			fps_calc_timer = SDL_GetTicks();
		}
		apply_surface(10, 10, message, screen);

		SDL_Flip(screen);
		frames++;

		delay = SDL_GetTicks() - fps_timer;

		/*  Socket 통신을 위한 부분 추가  */
		if (enemy_life != 0 && life != 0)
			switch (mode)
			{
				//server side
			case SERVER_MODE:
				//std::cout << "Client: ";
				recv(server, buffer_int, bufsize, 0);
				player2_position = buffer_int[0];
				player2_position_y = buffer_int[1];
				enemy_life = buffer_int[2];
				//std::cout << buffer_int[0] << " " << buffer_int[1] << " " << buffer_int[2] << std::endl;
				buffer_int[0] = player_position;
				buffer_int[1] = player_position_y;
				buffer_int[2] = life;
				caption2 << "Enemy Life: " << enemy_life;
				apply_surface(SCREEN_WIDTH - 10 - message2->w, 10, message2, screen);
				//std::cout << "Server: ";
				//std::cout << buffer_int[0] << " " << buffer_int[1] << " " << buffer_int[2] << std::endl;
				send(server, buffer_int, bufsize, 0);
				break;

				//client side
			case CLIENT_MODE:
				//std::cout << "Client: ";
				buffer_int[0] = player_position;
				buffer_int[1] = player_position_y;
				buffer_int[2] = life;
				//std::cout << buffer_int[0] << " " << buffer_int[1] << " " << buffer_int[2] << std::endl;
				send(client, buffer_int, bufsize, 0);
				//std::cout << "Server: ";
				recv(client, buffer_int, bufsize, 0);
				player2_position = buffer_int[0];
				player2_position_y = buffer_int[1];
				enemy_life = buffer_int[2];
				caption2 << "Enemy Life: " << enemy_life;
				apply_surface(SCREEN_WIDTH - 10 - message2->w, 10, message2, screen);
				//std::cout << buffer_int[0] << " " << buffer_int[1] << " " << buffer_int[2] << std::endl;
				break;
			case SINGLE_MODE:
				break;
			}

		if(life != 0 && enemy_life == 0 && (mode == SERVER_MODE || mode == CLIENT_MODE))
		{
			shutdown(client, SHUT_RDWR);
			shutdown(server, SHUT_RDWR);
			close(client);
			close(server);
			game_over(level, score, WINNER);//1 == WIN_CASE
			quit = true;
		}

		if (delay < 1000 / FRAMES_PER_SECOND)
		{
			SDL_Delay((1000 / FRAMES_PER_SECOND) - delay);
		}
	}
}

void init_ball()
{
	for (int i = 0; i < MAX_BALLS; i++)
	{
		SDL_Rect new_ball;
		new_ball.x = BALL_SIZE / 2 + rand() % (SCREEN_WIDTH - BALL_SIZE / 2);
		new_ball.y = -(5 + rand() % 350);
		new_ball.w = new_ball.h = BALL_SIZE;
		balls[i] = new_ball;
	}
}
void init_addlife()
{
	for (int i = 0; i < MAX_ADDLIFE; i++)
	{
		SDL_Rect new_addlife;
		new_addlife.x = ADDLIFE_SIZE / 2 + rand() % (SCREEN_WIDTH - ADDLIFE_SIZE / 2);
		new_addlife.y = -(5 + rand() % 350);
		new_addlife.w = new_addlife.h = ADDLIFE_SIZE;
		addlife[i] = new_addlife;
	}
}
void init_addscore()
{
	for (int i = 0; i < MAX_ADDSCORE; i++)
	{
		SDL_Rect new_addscore;
		new_addscore.x = ADDSCORE_SIZE / 2 + rand() % (SCREEN_WIDTH - ADDSCORE_SIZE / 2);
		new_addscore.y = -(5 + rand() % 350);
		new_addscore.w = new_addscore.h = ADDSCORE_SIZE;
		addscore[i] = new_addscore;
	}
}
void init_clear()
{
	for (int i = 0; i < MAX_CLEAR; i++)
	{
		SDL_Rect new_clear;
		new_clear.x = CLEAR_SIZE / 2 + rand() % (SCREEN_WIDTH - CLEAR_SIZE / 2);
		new_clear.y = -(5 + rand() % 350);
		new_clear.w = new_clear.h = CLEAR_SIZE;
		clear[i] = new_clear;
	}
}

void game_over(int level, int score, int state)
{
  Mix_PlayMusic(GameOver,-1);

	std::stringstream caption;
	std::stringstream caption2;
	switch (state)
	{
		//SINGLE_MODE
		case SINGLE_MODE:
		apply_surface(0, 0, background, screen);
		message = TTF_RenderText_Solid(font, "Game over", white);
		apply_surface((SCREEN_WIDTH - message->w) / 2, SCREEN_HEIGHT / 2 - message->h, message, screen);
		caption << "Level : " << level;
		message = TTF_RenderText_Solid(font, caption.str().c_str(), white);
		apply_surface((SCREEN_WIDTH - message->w) / 2, SCREEN_HEIGHT / 2 + message->h, message, screen);
		caption2 << "Score is : " << score;
		message = TTF_RenderText_Solid(font, caption2.str().c_str(), white);
		apply_surface((SCREEN_WIDTH - message->w) / 2, SCREEN_HEIGHT / 2 + message->h + 50, message, screen);
		SDL_Flip(screen);
		break;
		// 1 == WIN_CASE
		case WINNER:
		apply_surface(0, 0, background, screen);
		message = TTF_RenderText_Solid(font, "! ! ! YOU WIN ! ! !", white);
		apply_surface((SCREEN_WIDTH - message->w) / 2, SCREEN_HEIGHT / 2 - message->h, message, screen);
		SDL_Flip(screen);
		break;
		// 2 == LOSE_CASE
		case LOSER:
		apply_surface(0, 0, background, screen);
		message = TTF_RenderText_Solid(font, "( T . T ) YOU LOSE ( T . T )", white);
		apply_surface((SCREEN_WIDTH - message->w) / 2, SCREEN_HEIGHT / 2 - message->h, message, screen);
		SDL_Flip(screen);
		break;
	}

	while (true)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT ||
				(event.type == SDL_KEYDOWN &&
				(event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_ESCAPE)))
			{
				break;
			}
		}
	}
}
