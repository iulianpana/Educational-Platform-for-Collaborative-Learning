#include "versioncontrolmodule.h"

VersionControlModule::VersionControlModule()
{
}

void VersionControlModule::checkoutBranchToPath(QString projectPath, QString branch, QString link)
{    //According to
    //http://stackoverflow.com/questions/8551169/how-to-clone-fetch-a-git-repository-with-libgit2
    //there is no libgit2 equivalent to cloning branch without tracking all branches

    QString cdCmd = "cd " + projectPath;
    QString cmd =cdCmd + " ; " + "git remote add -t " +branch + " -f origin " + link +" " + projectPath +
            " ; " + "git checkout " + branch;


      system(cmd.toLocal8Bit().data());

}

bool VersionControlModule::push(QString dirPath)
 {
     // get the remote.
//     git_remote* remote = NULL;
//     git_repository *m_repository = NULL;
//     git_remote_lookup( &remote, m_repository, "origin" );

//     git_remote_callbacks callbacks = GIT_REMOTE_CALLBACKS_INIT;
//     //callbacks.credentials = cred_acquire_cb;

//     // connect to remote
//     git_remote_connect( remote, GIT_DIRECTION_PUSH, &callbacks,NULL );

//     // add a push refspec
//    // git_remote_add_push( remote, "refs/heads/master:refs/heads/master" );
//     // configure options
//     git_push_options options;
//     git_push_init_options( &options, GIT_PUSH_OPTIONS_VERSION );

//     // do the push
//     git_remote_upload( remote, NULL, &options );

     QString cmd = "cd " + dirPath + "; " + "git push";
     system(cmd.toLocal8Bit().data());
     return true;
 }
bool VersionControlModule::pull(QString dirPath)
 {
     // get the remote.
//     git_remote* remote = NULL;
//     git_repository *m_repository = NULL;
//     git_remote_lookup( &remote, m_repository, "origin" );

//     git_remote_callbacks callbacks = GIT_REMOTE_CALLBACKS_INIT;
//     //callbacks.credentials = cred_acquire_cb;

//     // connect to remote
//     git_remote_connect( remote, GIT_DIRECTION_PUSH, &callbacks,NULL );

//     // add a push refspec
//    // git_remote_add_push( remote, "refs/heads/master:refs/heads/master" );
//     // configure options
//     git_push_options options;
//     git_push_init_options( &options, GIT_PUSH_OPTIONS_VERSION );

//     // do the push
//     git_remote_upload( remote, NULL, &options );

     QString cmd = "cd " + dirPath + "; " + "git pull";
     system(cmd.toLocal8Bit().data());
     return true;
 }
