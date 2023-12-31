#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include <gbdk/console.h>
#include <rand.h>
//◻️のタイルデータ
unsigned char Tile[] =
{
  0xFF, 0xFF, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xFF, 0xFF, 
  0x18, 0x00, 0x7E, 0x00, 0x66, 0x00, 0xC3, 0x00, 
  0xC3, 0x00, 0x66, 0x00, 0x7E, 0x00, 0x18, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 
  0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 
  0x9E, 0xE0, 0x9E, 0xE0, 0x9E, 0xE0, 0x9E, 0xE0, 
  0x9E, 0xE0, 0x9E, 0xE0, 0x9E, 0xE0, 0x9E, 0xE0, 
  0xFF, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 
  0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 
  0x79, 0x07, 0x79, 0x07, 0x79, 0x07, 0x79, 0x07, 
  0x79, 0x07, 0x79, 0x07, 0x79, 0x07, 0x79, 0x07, 
  0x00, 0x00, 0x7F, 0x00, 0x7F, 0x00, 0x7F, 0x00, 
  0x7F, 0x00, 0x78, 0x07, 0x78, 0x07, 0x79, 0x07, 
  0x00, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 
  0xFE, 0x00, 0x1E, 0xE0, 0x1E, 0xE0, 0x9E, 0xE0, 
  0x9E, 0xE0, 0x1E, 0xE0, 0x1E, 0xE0, 0xFE, 0x00, 
  0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0x00, 0x00, 
  0x79, 0x07, 0x78, 0x07, 0x78, 0x07, 0x7F, 0x00, 
  0x7F, 0x00, 0x7F, 0x00, 0x7F, 0x00, 0x00, 0x00, 
  0xFF, 0x0E, 0xFF, 0x08, 0xFF, 0x7E, 0xFF, 0xFF, 
  0xBF, 0xBF, 0xBF, 0xBF, 0xFF, 0xFF, 0xFF, 0x7E
};
unsigned char Background[] = {
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
  0x03, 0x03, 0x03, 0x08, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x06, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x06, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x04, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x06, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x06, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x04, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x06, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x06, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x04, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x06, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x06, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x04, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x06, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x06, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x04, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x06, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x06, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x04, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x06, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x06, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x04, 0x02, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x06, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
  0x0A, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
  0x05, 0x05, 0x05, 0x09, 0x02, 0x02, 0x02, 0x02};

joypads_t joypads;
//四方向への移動ベクトル
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};

//プレイヤーの座標、方向変数
uint8_t player_x, player_y, direction;
//アイテムの座標
uint8_t item_x, item_y;
//点数用変数
int score;
//マップの左上のオリジン
uint8_t X = 48;
uint8_t Y = 32;

void main(void)
{
    //スタートボタンを押すまで待機する
    printf("PRESS START");
    waitpad(J_START);
    //LY レジスタの値取得 randのシード値として設定
    int seed = LY_REG;
    //各種変数初期化
    int counter = 1;
    int speed = 8;
    direction = score = 0;

    player_x = X;
    player_y = Y;
    //seed値設定
    initrand(seed);
    //スプライトタイルのロード
    set_sprite_data(0, 12, Tile);
    //バックグラウンドのタイルをロード
    set_bkg_data(0, 11, Tile); 
    //プレイヤースプライトをスプライト番号1に設定
    set_sprite_tile(1, 0);
    //アイテムスプライトをスプライト番号２に設定
    set_sprite_tile(2, 11);
    //プレイヤーをマップ内に移動
    move_sprite(1, player_x, player_y);
    //アイテム座標をランダムで設定
    item_x = X + rand()%10*8;
    item_y = Y + rand()%15*8;
    //アイテムのスプライトを移動
    move_sprite(2, item_x, item_y);
    //バックグランドを設定
    set_bkg_tiles(0, 0, 20, 18, Background); 
    //バックグラウンドとスプライトを表示
    SHOW_BKG; SHOW_SPRITES;

    while(1) 
    {
        //スコアを表示
        gotoxy(0,0);printf("SCORE:%d",score);
        //入力情報樹徳
        joypad_ex(&joypads);

        if (joypads.joy0 & J_UP) {
            direction = 1; 
        }
        if (joypads.joy0 & J_DOWN) {
            direction = 3; 
        }
        if (joypads.joy0 & J_RIGHT) {
            direction = 0; 
        }
        if (joypads.joy0 & J_LEFT) {
            direction = 2; 
        }
        //counterが特定の値になった場合
        if(speed != 0 && counter++%speed == 0){
            //プレイヤーの座標を移動
            player_x += 8*dx[direction];
            player_y += 8*dy[direction];
            //マップの壁に当たるかを判定
            if(player_x < X || player_x > X+9*8 || player_y < Y || player_y > Y+14*8){
                //スピードを0にする
                speed = 0;
            }
            //アイテムと同じ座標にいるか判定
            if(player_x == item_x && player_y == item_y){
                //スコアを1増やす
                score++;
                //アイテムの座標をランダムに移動させる
                item_x = X + rand()%10*8;
                item_y = Y + rand()%15*8;
                //アイテムを10個取得毎にスピードを1あげる
                if(speed > 1 && score%10 == 0){
                    speed--;
                }
            }
            //プレイヤーとアイテムのスプライトを描画する
            move_sprite(2, item_x, item_y);
            move_sprite(1, player_x, player_y);
        }
        //スピードが0の場合「GameOver」を表示する
        if(speed == 0){
            printf("\nGameOver");
        }
        wait_vbl_done();
    }
}