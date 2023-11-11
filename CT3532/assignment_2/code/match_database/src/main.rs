const COLS : usize = 10;
const ROWS : usize = 10;
const PLAYER_ID : u8 = 1;      // honestly this would be user input but effort

#[allow(dead_code)]

fn main() {
    // create the grid, a 2d array, created with the default values
    let mut grid: [[GridSquare; COLS]; ROWS] = Default::default();

    // now initialise each square's vector of timestamp pointers
    for row in &mut grid {
        for square in row.iter_mut() {
            square.timestamps = Vec::new();
        }
    }

    // init the players (just two) at three positions
    let player_1_1 : Player = Player{id: 0, x: 5, y: 8};
    let player_2_1 : Player = Player{id: 1, x: 8, y: 2};
    let player_1_2 : Player = Player{id: 0, x: 6, y: 8};
    let player_2_2 : Player = Player{id: 1, x: 9, y: 3};
    let player_1_3 : Player = Player{id: 0, x: 7, y: 8};
    let player_2_3 : Player = Player{id: 1, x: 8, y: 2};

    // then the timestamps, three total
    let timestamps : [Timestamp; 3] = [
        Timestamp {
            id : 0,
            players: vec! [player_1_1, player_2_1],
            ball : Ball { x: 0, y: 0, z: 0}
        },
        Timestamp {
            id : 1,
            players: vec! [player_1_2, player_2_2],
            ball : Ball { x: 0, y: 0, z: 0}
        },
        Timestamp {
            id : 2,
            players: vec! [player_1_3, player_2_3],
            ball : Ball { x: 0, y: 0, z: 0}
        }
    ];

    // for each timestamp, find the grids square the specified player is in, and add it to the timestamp pointer vector in that sqaure
    for timestamp in &timestamps {
        if let Some(square) = find_grid_square(timestamp, &mut grid) {
            square.timestamps.push(timestamp as *const Timestamp);
        }
    }

    println!("{:#?}", grid);

    // heatmap code
    // get the longest vector of timestamps, so that we can clamp the heatmap
        // i love rust
    let max_length = grid.iter()
        .flatten()
        .map( |sq| sq.timestamps.len())
        .max()
        .unwrap_or(0);

    let heatmap : [[f64; COLS]; ROWS] = grid.iter()
        .map(|row| 
                row.iter().map(|sq| {
                    if max_length == 0 {
                        0 as f64
                    } else {
                        (sq.timestamps.len() as f64) / (max_length as f64) 
                    }

                })
                .collect::<Vec<f64>>()
                .try_into()
                .expect("failed to convert to array")
            ).collect::<Vec<_>>()
            .try_into()
            .expect("failed to convert to 2d array");

    println!("{:#?}", heatmap);

}

fn find_grid_square<'a, 'b>(timestamp : &'a Timestamp, grid : &'b mut [[GridSquare; COLS]; ROWS]) -> Option<&'b mut GridSquare> {
    // assuming they're ordered by id to make it easier
    // although if i were really implementing this, their id would be unique to the player
    let search_player : &Player = &timestamp.players[PLAYER_ID as usize];

    // make sure the player is on the pitch
    if  (search_player.x >= 0 && search_player.x <= COLS as i8) 
            && 
        (search_player.y >= 0 && search_player.y <= ROWS as i8) 
    {
        return Some(& mut grid[search_player.x as usize][search_player.y as usize]);
    }

    // player could also not be on the pitch, e.g. during a lineout
    None
}




// data types
struct Timestamp {
    id : u32,
    players : Vec<Player>,
    ball : Ball
}

struct Player {
    pub id : u64,
    pub x : i8,
    pub y : i8
}

struct Ball {
    x : u8,
    y : u8,
    z : u8
}

#[derive(Default, Debug)]
struct GridSquare {
    timestamps :Vec<*const Timestamp>
}